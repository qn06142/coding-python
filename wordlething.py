#!/usr/bin/env python3
"""
Incremental Wordle helper (interactive, keeps state across guesses)

Usage:
 - Keep a file named 'wordlelist.txt' with 5-letter words (one per line).
 - Run this script. It will load the list and start an interactive session.

How to give feedback:
 - After you enter a guess, Wordle-style feedback is requested as a 5-char string containing:
     g for green (correct position)
     y for yellow (present, wrong position)
     b or . for black/gray (not present)
   Example: gyb.. or g y b . . (spaces are allowed)

Commands during the session:
 - suggest      : program will suggest one or several candidate guesses
 - list         : show remaining candidate words
 - reset        : start a new game (clears history)
 - quit / q / exit : exit the program

This implements proper handling of repeated letters by tracking per-letter min/max counts from feedback.
The update you asked for: prevent letters that are confirmed present (greens/yellows/min_counts > 0) from being marked as absent by later black feedback, and avoid duplicate yellow entries.
"""

import sys
from collections import Counter, defaultdict


def load_wordlist(filename='wordlelist.txt'):
    try:
        with open(filename, 'r') as f:
            return [w.strip().lower() for w in f if len(w.strip()) == 5 and w.strip().isalpha()]
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        sys.exit(1)


def normalize_feedback(s):
    s = s.lower().replace(' ', '')
    if len(s) != 5:
        return None
    out = []
    for ch in s:
        if ch in ('.', 'b', 'x'):
            out.append('b')
        elif ch == 'g':
            out.append('g')
        elif ch == 'y':
            out.append('y')
        else:
            return None
    return ''.join(out)


def update_constraints_from_feedback(guess, feedback, constraints):
    """Update constraints dict using a guess and Wordle feedback.

    constraints is a dict with keys:
      - greens: dict pos->letter
      - yellows: list of (pos, letter)
      - min_counts: Counter(letter->min occurrences required)
      - max_counts: dict letter->max occurrences allowed (optional)
      - excluded: set of letters known to be absent (max_count 0)

    This function ensures that positive evidence (greens/yellows/min_counts > 0)
    always overrides any later black feedback that would otherwise mark a letter absent.
    It also avoids duplicate yellow entries for the same position.
    """
    greens = constraints['greens']
    yellows = constraints['yellows']
    min_counts = constraints['min_counts']
    max_counts = constraints['max_counts']
    excluded = constraints['excluded']

    # First pass: count g/y occurrences per letter in this guess
    gy_counts = Counter()
    for i, (gch, fb) in enumerate(zip(guess, feedback)):
        if fb in ('g', 'y'):
            gy_counts[gch] += 1

    # Second pass: apply positional rules and set max/min counts
    for i, (gch, fb) in enumerate(zip(guess, feedback)):
        if fb == 'g':
            greens[i] = gch
            # the total occurrences required is at least the number of g/y in this guess
            min_counts[gch] = max(min_counts[gch], gy_counts[gch])
            # if it was previously marked excluded, clear that because we now have positive evidence
            if max_counts.get(gch) == 0:
                max_counts.pop(gch, None)
                excluded.discard(gch)
        elif fb == 'y':
            # avoid duplicate yellow for the same position
            if not any(pos == i and ch == gch for (pos, ch) in yellows):
                yellows.append((i, gch))
            min_counts[gch] = max(min_counts[gch], gy_counts[gch])
            # clear any accidental exclusion
            if max_counts.get(gch) == 0:
                max_counts.pop(gch, None)
                excluded.discard(gch)
        elif fb == 'b':
            # If this letter appears as g/y somewhere in this SAME guess, the b means the total
            # occurrences in the target equals gy_counts[gch] (we've already set min to that).
            if gy_counts[gch] > 0:
                # set an upper bound equal to number of g/y seen in this guess
                max_counts[gch] = gy_counts[gch]
                min_counts[gch] = max(min_counts[gch], gy_counts[gch])
                # ensure it's not marked excluded
                excluded.discard(gch)
            else:
                # No g/y evidence in THIS guess. Check if we have positive evidence from previous guesses.
                if min_counts.get(gch, 0) > 0 or any(ch == gch for (pos, ch) in yellows) or gch in greens.values():
                    # We have positive evidence from previous guesses: this black just means the max equals known min
                    max_counts[gch] = max_counts.get(gch, min_counts.get(gch, 0))
                    # do not mark as excluded
                    excluded.discard(gch)
                else:
                    # mark as excluded (absent)
                    max_counts[gch] = 0
                    excluded.add(gch)

    # Final reconciliation: if any letter has min_counts > 0, it cannot be excluded
    for ch, mn in list(min_counts.items()):
        if mn > 0 and max_counts.get(ch) == 0:
            max_counts.pop(ch, None)
            excluded.discard(ch)


def word_matches_constraints(word, constraints):
    greens = constraints['greens']
    yellows = constraints['yellows']
    min_counts = constraints['min_counts']
    max_counts = constraints['max_counts']

    # Check greens
    for pos, ch in greens.items():
        if word[pos] != ch:
            return False

    # Check yellows (letter must be present somewhere else)
    for pos, ch in yellows:
        if word[pos] == ch:
            return False
        if ch not in word:
            return False

    # Check counts
    wc = Counter(word)
    # min counts
    for ch, mn in min_counts.items():
        if wc[ch] < mn:
            return False
    # max counts
    for ch, mx in max_counts.items():
        if wc[ch] > mx:
            return False
    return True


def score_word_by_frequency(word, freqs):
    # Score by sum of frequencies of unique letters to favor informative guesses
    seen = set()
    s = 0
    for ch in word:
        if ch not in seen:
            s += freqs.get(ch, 0)
            seen.add(ch)
    return s


def suggest_words(candidates, n=10):
    # Build letter frequency from current candidates
    freqs = Counter()
    for w in candidates:
        for ch in set(w):
            freqs[ch] += 1
    scored = [(score_word_by_frequency(w, freqs), w) for w in candidates]
    scored.sort(reverse=True)
    return [w for _, w in scored[:n]]


def interactive_loop(wordlist):
    candidates = list(wordlist)
    constraints = {
        'greens': {},            # pos->letter
        'yellows': [],           # list of (pos, letter)
        'min_counts': Counter(), # letter->min required
        'max_counts': {},        # letter->max allowed
        'excluded': set(),
    }
    history = []  # list of (guess, feedback)

    print("Wordle incremental helper. Type 'suggest' to get suggestions, 'list' to see candidates, 'reset' to start over, 'quit' to exit.")

    while True:
        cmd = input("Enter your guess (or command): ").strip().lower()
        if cmd in ('q', 'quit', 'exit'):
            print('Goodbye!')
            return
        if cmd == 'reset':
            candidates = list(wordlist)
            constraints = {'greens': {}, 'yellows': [], 'min_counts': Counter(), 'max_counts': {}, 'excluded': set()}
            history.clear()
            print('State reset. You can start a new game.')
            continue
        if cmd == 'suggest':
            suggestions = suggest_words(candidates, n=10)
            print('Suggestions (best first):', ', '.join(suggestions))
            continue
        if cmd == 'list':
            print(f"{len(candidates)} candidates:")
            if len(candidates) <= 200:
                print(', '.join(candidates))
            else:
                print(', '.join(candidates[:100]) + ', ...')
            continue

        # otherwise assume this is a guess
        guess = cmd
        if len(guess) != 5 or not guess.isalpha():
            print('Please enter a 5-letter word, or a command.')
            continue
        if guess not in wordlist:
            print('Warning: guess not in word list. You can still use it, but suggestions come from the list.')

        raw_fb = input('Enter feedback (g=green, y=yellow, b/.=black), e.g. gyb.. : ')
        fb = normalize_feedback(raw_fb)
        if fb is None:
            print('Invalid feedback. Use 5 characters from g,y,b or .')
            continue

        history.append((guess, fb))
        update_constraints_from_feedback(guess, fb, constraints)

        # Filter candidates
        new_cands = [w for w in candidates if word_matches_constraints(w, constraints)]
        candidates = new_cands

        # Report
        print(f"After {len(history)} guess(es): {len(candidates)} candidates remain.")
        if len(candidates) == 0:
            print('No possible words remain with the current constraints. Consider resetting or checking your feedback for mistakes.')
        elif len(candidates) <= 20:
            print(', '.join(candidates))
        else:
            print(', '.join(candidates[:20]) + ', ...')

        # If solved
        if any(fb == 'ggggg' for (_, fb) in history):
            print('Solved! Starting a new game (state cleared).')
            candidates = list(wordlist)
            constraints = {'greens': {}, 'yellows': [], 'min_counts': Counter(), 'max_counts': {}, 'excluded': set()}
            history.clear()


def main():
    wordlist = load_wordlist()
    interactive_loop(wordlist)


if __name__ == '__main__':
    main()
