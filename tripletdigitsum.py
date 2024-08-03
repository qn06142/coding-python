def digit_sum(x):
    return sum(int(d) for d in str(x))

def precompute_digit_sums(limit):
    digsum = [0] * (limit + 1)
    for i in range(limit + 1):
        digsum[i] = digit_sum(i)
    return digsum

def count_good_triples(n, digsum):
    digsum_n = digsum[n]
    count = 0
    
    # Using modulo 9 property to simplify the problem
    mod_count = [0] * 9
    
    for i in range(n + 1):
        mod_count[digsum[i] % 9] += 1

    for a_mod in range(9):
        for b_mod in range(9):
            c_mod = (digsum_n - a_mod - b_mod) % 9
            if c_mod < 0:
                c_mod += 9
            count += mod_count[a_mod] * mod_count[b_mod] * mod_count[c_mod]
    
    return count

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    queries = [int(data[i]) for i in range(1, t + 1)]
    
    max_n = max(queries)
    digsum = precompute_digit_sums(max_n)
    
    results = []
    for n in queries:
        results.append(count_good_triples(n, digsum))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
