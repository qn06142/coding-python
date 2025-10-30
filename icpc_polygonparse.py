#!/usr/bin/env python3
"""
marshal_solutions.py

Parse solution blocks, transform block_text according to found_exact, and produce gzipped+base64 mapping.

Usage:
    python marshal_solutions.py -i solutions.txt           # prints base64 to stdout
    python marshal_solutions.py -i solutions.txt -o out.b64
    python marshal_solutions.py -i solutions.txt --format json
"""

import re
import sys
import argparse
import gzip
import base64
import pickle

# Capture n, k and found_exact from the header line.
# Example header:
#   # Solution n=21 k=86 found_exact=False time=11.708s gen=1 diags=94
HEADER_RE = re.compile(
    r'^\s*#\s*Solution\s+'
    r'n=(?P<n>-?\d+)\s+'
    r'k=(?P<k>-?\d+)\s+'
    r'found_exact=(?P<found_exact>[^ \t\r\n]+)\b.*$',
    re.MULTILINE
)


def truthy_str(s: str) -> bool:
    """Return True for common truthy string values."""
    if s is None:
        return False
    s = s.strip().lower()
    return s in ("1", "true", "t", "yes", "y")


def parse_solution_blocks(text: str):
    """
    Parse all solution blocks from text.

    For each header match we grab the block (header -> next header or EOF).
    Then we transform block_text *exactly* as requested:
        raw block_text = text[start:end].rstrip()
        if found_exact is truthy:
            block_text = "Yes" + '\n'.join(block_text.splitlines()[2:])
        else:
            block_text = "No"

    Returns:
        dict mapping (int(n), int(k)) -> transformed_block_text (str)
    """
    matches = list(HEADER_RE.finditer(text))
    if not matches:
        return {}

    blocks = {}
    for i, m in enumerate(matches):
        n = int(m.group('n'))
        k = int(m.group('k'))
        found_exact_raw = m.group('found_exact')
        start = m.start()
        end = matches[i + 1].start() if (i + 1) < len(matches) else len(text)
        raw_block_text = text[start:end].rstrip()

        # Apply the exact transformation from your snippet:
        # block_text = "Yes" + '\n'.join(block_text.splitlines()[2:])
        # found = m.group("found_exact")
        # if not found:
        #     block_text = "No"
        if truthy_str(found_exact_raw):
            lines = raw_block_text.splitlines()
            # replicate '\n'.join(block_text.splitlines()[2:])
            rest = "\n".join(lines[2:]) if len(lines) > 2 else ""
            # If there is any rest, prefix with a newline between "Yes" and rest
            block_text = "Yes" + (("\n" + rest) if rest else "")
        else:
            block_text = "No"

        key = (n, k)
        if key in blocks:
            print(f"Warning: duplicate entry for (n,k)={key}, overwriting previous entry", file=sys.stderr)
        blocks[key] = block_text
    return blocks


def marshal_and_encode(mapping, fmt='pickle'):
    """
    Marshal the mapping and return a base64-encoded gzip of the marshalled bytes.

    fmt:
      - 'pickle': use pickle.dumps(mapping) so tuple keys are preserved (default)
      - 'json'  : convert keys to "n,k" strings and dump json bytes (utf-8)
    """
    if fmt not in ('pickle', 'json'):
        raise ValueError("fmt must be 'pickle' or 'json'")

    if fmt == 'pickle':
        raw_bytes = pickle.dumps(mapping, protocol=pickle.HIGHEST_PROTOCOL)
    else:
        import json
        json_friendly = {f"{k0},{k1}": v for (k0, k1), v in mapping.items()}
        raw_bytes = json.dumps(json_friendly, ensure_ascii=False).encode('utf-8')

    gzipped = gzip.compress(raw_bytes)
    b64 = base64.b64encode(gzipped).decode('ascii')
    return b64


def main(argv=None):
    p = argparse.ArgumentParser(description="Parse solution blocks and produce gzipped+base64 encoded mapping (with found_exact transform).")
    p.add_argument('-i', '--input', help="Input file (default: stdin)")
    p.add_argument('-o', '--output', help="Output file to write base64 string (default: stdout)")
    p.add_argument('--format', choices=['pickle', 'json'], default='pickle',
                   help="Marshal format. 'pickle' preserves tuple keys; 'json' converts keys to 'n,k' strings.")
    args = p.parse_args(argv)

    # read input
    if args.input:
        with open(args.input, 'r', encoding='utf-8') as f:
            text = f.read()
    else:
        text = sys.stdin.read()

    mapping = parse_solution_blocks(text)
    if not mapping:
        print("No solution blocks found in input.", file=sys.stderr)
        sys.exit(2)

    b64 = marshal_and_encode(mapping, fmt=args.format)

    if args.output:
        with open(args.output, 'w', encoding='ascii') as f:
            f.write(b64)
        print(f"Encoded output written to {args.output}", file=sys.stderr)
    else:
        print(b64)


if __name__ == '__main__':
    main()
