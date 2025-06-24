import sys


def load_wordlist(filename):
    try:
        with open(filename, 'r') as f:
            return [w.strip().lower() for w in f if len(w.strip()) == 5]
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        sys.exit(1)


def get_input(prompt, length=None):
    while True:
        s = input(prompt).strip().lower()
        if length and len(s) != length:
            print(f"Please enter exactly {length} characters.")
        else:
            return s


def find_matches(wordlist, prefix, include, exclude):
    matches = []
    for w in wordlist:
        # Check prefix letters
        if any(p != '.' and w[i] != p for i, p in enumerate(prefix)):
            continue
        # Check included letters
        if any(ch not in w for ch in include):
            continue
        # Check excluded letters
        if any(ch in w for ch in exclude):
            continue
        matches.append(w)
    return matches


def main():
    wordlist = load_wordlist('wordlelist.txt')
    print("Wordle helper (5-letter words)")
    while True:
        prefix = get_input("Enter pattern (use '.' for unknown letters), or 'q' to quit: ", length=5)
        if prefix == 'q':
            break
        include = input("Enter letters that must appear (no separators), or leave blank: ").strip().lower()
        exclude = input("Enter letters to exclude (no separators), or leave blank: ").strip().lower()

        matches = find_matches(wordlist, prefix, include, exclude)
        if matches:
            print(f"Matches ({len(matches)}): {', '.join(matches)}")
        else:
            print("No matches found.")
        print()

if __name__ == '__main__':
    main()
