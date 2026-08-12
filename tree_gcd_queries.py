#!/usr/bin/env python3
import os
import random
import subprocess
import sys
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
DEFAULT_REF = SCRIPT_DIR / "tree_gcd_queries"
DEFAULT_CAND = SCRIPT_DIR / "tree_gcd_queries1"
REF_SRC = SCRIPT_DIR / "tree_gcd_queries.cpp"
CAND_SRC = SCRIPT_DIR / "tree_gcd_queries1.cpp"


def build_binary(src: Path, binary: Path) -> None:
    if binary.exists():
        return
    print(f"Compiling {src.name} -> {binary.name}")
    subprocess.check_call([
        "g++",
        "-std=c++17",
        "-O2",
        "-Wall",
        "-Wextra",
        str(src),
        "-o",
        str(binary),
    ], cwd=str(SCRIPT_DIR))


def generate_case() -> str:
    n = random.randint(1, 7)
    q = random.randint(1, 10)

    edges = []
    for v in range(2, n + 1):
        u = random.randint(1, v - 1)
        w = random.randint(1, 20)
        edges.append((u, v, w))

    queries = []
    for _ in range(q):
        u = random.randint(1, n)
        v = random.randint(1, n)
        queries.append((u, v))

    lines = [f"{n} {q}"]
    for u, v, w in edges:
        lines.append(f"{u} {v} {w}")
    for u, v in queries:
        lines.append(f"{u} {v}")
    return "\n".join(lines) + "\n"


def run_program(binary: Path, data: str) -> str:
    proc = subprocess.Popen(
        [str(binary)],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        cwd=str(SCRIPT_DIR),
    )
    out, err = proc.communicate(input=data.encode())
    if proc.returncode != 0:
        raise RuntimeError(f"Program {binary.name} failed with exit code {proc.returncode}\nSTDERR:\n{err.decode()}")
    return out.decode().strip()


def main() -> int:
    random.seed(0)

    if len(sys.argv) >= 3:
        ref_bin = Path(sys.argv[1]).resolve()
        cand_bin = Path(sys.argv[2]).resolve()
    else:
        ref_bin = DEFAULT_REF
        cand_bin = DEFAULT_CAND

    if not ref_bin.exists():
        build_binary(REF_SRC, ref_bin)
    if not cand_bin.exists():
        build_binary(CAND_SRC, cand_bin)

    test_count = int(sys.argv[3]) if len(sys.argv) >= 4 else 1000

    for i in range(1, test_count + 1):
        case = generate_case()
        ref_out = run_program(ref_bin, case)
        cand_out = run_program(cand_bin, case)
        if ref_out != cand_out:
            print(f"Mismatch found on test #{i}")
            print("Input:")
            print(case, end="")
            print("Reference output:")
            print(ref_out)
            print("Candidate output:")
            print(cand_out)
            return 1
        if i % 100 == 0:
            print(f"Checked {i} cases...")

    print(f"All {test_count} test cases passed.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
