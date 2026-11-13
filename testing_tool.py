#!/usr/bin/env python3

"""
Local testing tool for Guess the Permutation.

Disclaimer: This is NOT the same code used to test your solution when it is
submitted. This local tool is non-adaptive: it reads a fixed permutation from
the input data file and answers all queries according to that permutation. The
tool is provided as-is for local debugging only. It does not enforce the time
and memory limits used by the judge.

The behavior is controlled by an input data file.
The first line contains an integer T, the number of test cases.
For each test case:
  - one integer n;
  - n + 1 integers p_0, p_1, ..., p_n, forming a permutation of 0, 1, ..., n.

Example data file:
1
3
2 0 3 1

The testing tool is run like this:

    python3 testing_tool.py [--quiet] <data_file> <program> [args...]

Examples:

    python3 testing_tool.py sample.in ./solution
    python3 testing_tool.py sample.in java -cp . Solution
    python3 testing_tool.py sample.in python3 solution.py

The tool logs the complete interaction. If you do not want that, pass
--quiet before the data file name.
"""

from __future__ import annotations

import argparse
import subprocess
import sys
from dataclasses import dataclass
from typing import List


verbose = True
process: subprocess.Popen[str] | None = None


class WrongAnswer(RuntimeError):
    pass


class EndOfFile(RuntimeError):
    pass


@dataclass
class TestCase:
    n: int
    perm: List[int]


def vprint(*args, **kwargs) -> None:
    if verbose:
        print("< ", end="")
        print(*args, **kwargs)
        sys.stdout.flush()
    assert process is not None and process.stdin is not None
    print(*args, file=process.stdin, flush=True, **kwargs)


def vreadline() -> str:
    assert process is not None and process.stdout is not None
    line = process.stdout.readline()
    if verbose and line:
        print("> " + line.rstrip("\n"))
    if not line:
        raise EndOfFile("The program terminated or closed stdout unexpectedly.")
    return line


def parse_int(token: str, what: str) -> int:
    try:
        return int(token)
    except ValueError as exc:
        raise WrongAnswer(f"{what} is not an integer: {token!r}") from exc


def read_data_file(path: str) -> List[TestCase]:
    with open(path, "r", encoding="utf-8") as file:
        tokens = file.read().strip().split()
    if not tokens:
        raise ValueError("The data file is empty.")

    pos = 0

    def next_token(name: str) -> str:
        nonlocal pos
        if pos >= len(tokens):
            raise ValueError(f"Expected {name}, but reached end of data file.")
        token = tokens[pos]
        pos += 1
        return token

    try:
        t = int(next_token("T"))
    except ValueError as exc:
        raise ValueError("T must be an integer.") from exc
    if t < 1:
        raise ValueError("T must be at least 1.")

    tests: List[TestCase] = []
    total_n = 0
    for case_id in range(1, t + 1):
        try:
            n = int(next_token(f"n for test case #{case_id}"))
        except ValueError as exc:
            raise ValueError(f"n for test case #{case_id} must be an integer.") from exc
        if n < 1:
            raise ValueError(f"n for test case #{case_id} must be at least 1.")
        total_n += n
        if total_n > 100000:
            raise ValueError("The sum of n over all test cases must not exceed 100000.")

        perm = []
        for i in range(n + 1):
            try:
                value = int(next_token(f"p_{i} for test case #{case_id}"))
            except ValueError as exc:
                raise ValueError(
                    f"p_{i} for test case #{case_id} must be an integer."
                ) from exc
            if not (0 <= value <= n):
                raise ValueError(
                    f"p_{i} for test case #{case_id} is {value}, outside [0,{n}]."
                )
            perm.append(value)

        if sorted(perm) != list(range(n + 1)):
            raise ValueError(f"The permutation in test case #{case_id} is invalid.")
        tests.append(TestCase(n, perm))

    if pos != len(tokens):
        raise ValueError("The data file contains extra tokens after the last test case.")
    return tests


def start_process(program: List[str]) -> None:
    global process
    if verbose:
        print("[run] " + " ".join(program))
    process = subprocess.Popen(
        program,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        text=True,
        bufsize=1,
    )
    if process.stdin is None or process.stdout is None:
        raise RuntimeError("Failed to open pipes to the tested program.")


def check_answer(case_id: int, n: int, expected: List[int], tokens: List[str]) -> None:
    if len(tokens) != n + 2:
        raise WrongAnswer(
            f"Test case #{case_id}: answer must contain {n + 1} integers."
        )

    answer = [parse_int(tokens[i + 1], f"answer p_{i}") for i in range(n + 1)]
    seen = [False] * (n + 1)
    for i, value in enumerate(answer):
        if not (0 <= value <= n):
            raise WrongAnswer(
                f"Test case #{case_id}: answer p_{i}={value} is outside [0,{n}]."
            )
        if seen[value]:
            raise WrongAnswer(
                f"Test case #{case_id}: answer is not a permutation, "
                f"value {value} appears more than once."
            )
        seen[value] = True

    if answer != expected:
        raise WrongAnswer(f"Test case #{case_id}: wrong permutation reported.")


def run_interaction(tests: List[TestCase]) -> None:
    vprint(len(tests))

    for case_id, test in enumerate(tests, start=1):
        n = test.n
        perm = test.perm
        pos = [0] * (n + 1)
        for i, value in enumerate(perm):
            pos[value] = i

        vprint(n)
        queries = 0
        limit = n + 40

        while True:
            line = vreadline().strip()
            if not line:
                raise WrongAnswer(f"Test case #{case_id}: empty output line.")

            tokens = line.split()
            command = tokens[0]
            if command == "?":
                if len(tokens) != 3:
                    raise WrongAnswer(
                        f"Test case #{case_id}: query must have format '? i j'."
                    )
                queries += 1
                if queries > limit:
                    raise WrongAnswer(
                        f"Test case #{case_id}: query limit {limit} exceeded."
                    )
                i = parse_int(tokens[1], "query index i")
                j = parse_int(tokens[2], "query index j")
                if not (0 <= i <= n):
                    raise WrongAnswer(
                        f"Test case #{case_id}: query index i={i} is outside [0,{n}]."
                    )
                if not (0 <= j <= n):
                    raise WrongAnswer(
                        f"Test case #{case_id}: query index j={j} is outside [0,{n}]."
                    )
                value = abs(perm[i] - perm[j])
                vprint(pos[value])
            elif command == "!":
                check_answer(case_id, n, perm, tokens)
                break
            else:
                raise WrongAnswer(
                    f"Test case #{case_id}: expected '?' or '!', got {command!r}."
                )


def main() -> int:
    parser = argparse.ArgumentParser(
        usage="%(prog)s [--quiet] data.in program [args...]"
    )
    parser.add_argument(
        "--quiet", "-q", action="store_true", help="Do not show interactions"
    )
    parser.add_argument("data", help="Input data file for the local testing tool")
    parser.add_argument("program", nargs=argparse.REMAINDER, help="Program to run")
    args = parser.parse_args()

    global verbose
    verbose = not args.quiet

    if not args.program:
        parser.error("Must specify a program to run.")

    tests = read_data_file(args.data)
    start_process(args.program)
    try:
        run_interaction(tests)
    finally:
        assert process is not None
        if process.stdin is not None:
            process.stdin.close()

    assert process is not None
    process.wait()
    if process.returncode != 0:
        raise WrongAnswer(f"The program exited with code {process.returncode}.")

    print("OK: accepted.", file=sys.stderr)
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (WrongAnswer, ValueError, EndOfFile) as exc:
        print(f"Error: {exc}", file=sys.stderr)
        sys.exit(1)
