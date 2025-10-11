#!/usr/bin/env python3
"""
Interactive judge for "Find Array" problem (n = 7).
Runs a single executable (default ./find_array) and simulates judge responses.

Behavior:
- Generates a random permutation of 1..7 with pos(1) < pos(7).
- Reads contestant's stdout line-by-line (background reader thread).
- Interprets lines with integers:
    * If a line has exactly 7 ints -> treat as final answer and validate.
    * Else, treat ints as one or more query pairs (l, r) and respond with max-min.
- Enforces ≤ 12 queries.
- Detects invalid queries (out-of-range or l > r) -> WA.
- Detects timeouts (no output) -> TLE.

Adjust `executable` and `TIMEOUT_SECONDS` as needed.
"""
import subprocess
import threading
import queue
import random
import time
import sys

# ---------- Configuration ----------
executable = "./find_array"   # path to contestant executable
TIMEOUT_SECONDS = 3.0         # seconds waiting for next line of output before TLE
MAX_QUERIES = 12
N = 7
# -----------------------------------

def make_perm():
    perm = list(range(1, N+1))
    while True:
        random.shuffle(perm)
        if perm.index(1) < perm.index(N):
            return perm

def reader_thread(proc, q, stop_event):
    """
    Read lines from proc.stdout and push to queue.
    Stops when stdout EOF or stop_event set.
    """
    try:
        while not stop_event.is_set():
            line = proc.stdout.readline()
            if line == '':
                # EOF
                break
            # keep raw line (strip only trailing newline)
            q.put(line.rstrip('\n'))
    except Exception as e:
        # reading error (process likely died)
        pass
    finally:
        # signal EOF
        q.put(None)

def send_response(proc, s):
    try:
        proc.stdin.write(s + "\n")
        proc.stdin.flush()
    except Exception:
        pass

def run_one_test():
    perm = make_perm()
    print("Secret permutation:", perm)
    # start subprocess
    try:
        proc = subprocess.Popen(
            [executable],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,  # line-buffered
        )
    except FileNotFoundError as e:
        print("Executable not found:", executable)
        return False

    q = queue.Queue()
    stop_event = threading.Event()
    t = threading.Thread(target=reader_thread, args=(proc, q, stop_event), daemon=True)
    t.start()

    tokens_pending = []   # pending integer tokens (strings) not yet consumed
    queries_used = 0
    verdict = None
    stderr_collected = []
    start_time = time.time()

    def collect_stderr():
        try:
            err = proc.stderr.read()
            if err:
                stderr_collected.append(err)
        except Exception:
            pass

    # main loop: process lines as they arrive
    eof_received = False
    while True:
        try:
            line = q.get(timeout=TIMEOUT_SECONDS)
        except queue.Empty:
            # No output in TIMEOUT_SECONDS
            # Kill process and report TLE
            proc.kill()
            collect_stderr()
            print("Result: TLE (no output for {:.1f}s)".format(TIMEOUT_SECONDS))
            verdict = ("TLE", "no output")
            break

        if line is None:
            # reader signaled EOF
            eof_received = True
            # after EOF, try to drain any final buffered tokens from proc.stdout (if any)
            collect_stderr()
            # break to finalization step
            break

        stripped = line.strip()
        if stripped == "":
            # ignore blank lines
            continue

        # Try to parse integers out of the line
        parts = stripped.split()
        ints = []
        parse_ok = True
        for p in parts:
            try:
                ints.append(int(p))
            except ValueError:
                parse_ok = False
                break

        if not parse_ok:
            # Received non-integer output. Consider it protocol error.
            proc.kill()
            collect_stderr()
            print("Result: WA (non-integer output received)")
            print("Offending line:", repr(line))
            verdict = ("WA", "non-integer output")
            break

        # If this line contains exactly 7 integers and the program likely intends this to be final answer:
        if len(ints) == N:
            # treat as final answer
            answer = ints
            # Validate answer: permutation of 1..N
            ok_perm = sorted(answer) == list(range(1, N+1))
            pos1_before_posN = answer.index(1) < answer.index(N) if ok_perm else False
            if not ok_perm:
                proc.kill()
                print("Result: WA (output is not a permutation of 1..7)")
                print("Output:", answer)
                verdict = ("WA", "not a permutation")
                break
            if not pos1_before_posN:
                proc.kill()
                print("Result: WA (1 does not appear before 7 in output)")
                print("Output:", answer)
                verdict = ("WA", "order constraint violated")
                break
            # compare to secret
            if answer == perm:
                proc.kill()
                print("Result: AC")
                verdict = ("AC", "")
                break
            else:
                proc.kill()
                print("Result: WA (wrong permutation)")
                print("Expected:", perm)
                print("Got     :", answer)
                verdict = ("WA", "wrong permutation")
                break

        # Otherwise, treat integers as queries or partial tokens.
        # We'll append these tokens and consume pairs as queries.
        for v in ints:
            tokens_pending.append(v)

        # consume as many (l, r) pairs as possible
        while len(tokens_pending) >= 2:
            l = tokens_pending.pop(0)
            r = tokens_pending.pop(0)
            # Validate query range
            if not (1 <= l <= N and 1 <= r <= N and l <= r):
                # invalid query -> immediate -1 and WA
                try:
                    send_response(proc, "-1")
                except Exception:
                    pass
                proc.kill()
                collect_stderr()
                print("Result: WA (invalid query: l={}, r={})".format(l, r))
                verdict = ("WA", "invalid query")
                break

            # Answer query
            queries_used += 1
            a_segment = perm[l-1:r]
            ans = max(a_segment) - min(a_segment)
            send_response(proc, str(ans))
            # Enforce max queries
            if queries_used > MAX_QUERIES:
                proc.kill()
                collect_stderr()
                print("Result: WA (too many queries: {})".format(queries_used))
                verdict = ("WA", "too many queries")
                break
        if verdict is not None:
            break

    # Finalization: if EOF happened and there are leftover tokens which might represent the final answer
    if verdict is None and eof_received:
        # If after EOF there are still pending tokens, try to interpret them as final answer:
        if len(tokens_pending) >= N:
            cand = tokens_pending[:N]
            ok_perm = sorted(cand) == list(range(1, N+1))
            pos1_before_posN = cand.index(1) < cand.index(N) if ok_perm else False
            if ok_perm and pos1_before_posN and cand == perm:
                print("Result: AC (found on EOF tokens)")
                verdict = ("AC","")
            else:
                print("Result: WA (on EOF). Candidate:", cand, "Expected:", perm)
                verdict = ("WA","EOF candidate mismatch")
        else:
            # no final answer provided
            print("Result: WA (no final answer provided before EOF).")
            verdict = ("WA", "no final answer")

    # Print stderr if any and verdict != AC (helpful for debugging)
    if verdict and verdict[0] != "AC":
        if stderr_collected:
            print("--- program stderr ---")
            for s in stderr_collected:
                print(s)
        else:
            # attempt to fetch stderr again
            try:
                more_err = proc.stderr.read()
                if more_err:
                    print("--- program stderr ---")
                    print(more_err)
            except Exception:
                pass

    # Ensure process is terminated
    try:
        proc.kill()
    except Exception:
        pass
    try:
        proc.wait(timeout=0.5)
    except Exception:
        pass

    return verdict[0] == "AC"

if __name__ == "__main__":
    random.seed()
    wa = 0
    tot = 0
    while(True):
        success = run_one_test()
        if not success:
            #sys.exit(0 if success else 1)
            wa += 1
        tot += 1
        print((tot - wa)/ (tot) * 100)
