import sys

def minimal_lcm_for_sum(n: int) -> int:

    if n % 2 == 0:
        return n // 2

    limit = int(n**0.5)
    for d in range(3, limit+1, 2):
        if n % d == 0:

            return n - (n // d)

    return n - 1

def main():
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    out = []
    for i in range(1, t+1):
        n = int(data[i])
        out.append(str(minimal_lcm_for_sum(n)))
    sys.stdout.write("\n".join(out))

if __name__ == '__main__':
    main()