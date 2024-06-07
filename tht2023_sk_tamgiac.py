def sieve_of_eratosthenes(max_num):
    is_prime = [True] * (max_num + 1)
    p = 2
    while p * p <= max_num:
        if is_prime[p]:
            for i in range(p * p, max_num + 1, p):
                is_prime[i] = False
        p += 1
    is_prime[0], is_prime[1] = False, False  # 0 and 1 are not prime numbers
    return is_prime

def count_triangles(n, is_prime):
    from collections import defaultdict
    
    # Create adjacency lists
    green_edges = defaultdict(set)
    yellow_edges = defaultdict(set)
    
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            if is_prime[i + j]:
                green_edges[i].add(j)
                green_edges[j].add(i)
            else:
                yellow_edges[i].add(j)
                yellow_edges[j].add(i)
    
    def count_triangles_in_edges(edges):
        triangle_count = 0
        for u in edges:
            for v in edges[u]:
                if v > u:
                    common_neighbors = edges[u].intersection(edges[v])
                    triangle_count += len(common_neighbors)
        return triangle_count // 3
    
    green_triangles = count_triangles_in_edges(green_edges)
    yellow_triangles = count_triangles_in_edges(yellow_edges)
    
    return green_triangles + yellow_triangles

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])
    results = []
    
    # Precompute all primes up to 2 * 1000000 (since maximum i+j is 2000000)
    is_prime = sieve_of_eratosthenes(2000000)
    
    for i in range(1, T + 1):
        n = int(data[i])
        results.append(count_triangles(n, is_prime))
    
    for result in results:
        print(result)

# To run the main function when the script is executed
if __name__ == "__main__":
    main()