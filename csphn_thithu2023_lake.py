
def compute_max_areas(limit):
    import math

    # Generate primitive triples
    for m in range(2, int(math.sqrt(limit // 2)) + 1):
        for n in range(1, m):
            if (m - n) % 2 == 1 and math.gcd(m, n) == 1:
                a = m * m - n * n
                b = 2 * m * n
                c = m * m + n * n
                p = a + b + c
                if p > limit:
                    break
                area = a * b // 2
                for k in range(1, limit // p + 1):
                    kp = k * p
                    Result[kp] = max(Result[kp], area * k * k)

    return Result

limit = 10**6
precomputed_results = compute_max_areas(limit)

for _ in range(0, int(input())):
    print(precomputed_results[int(input())])