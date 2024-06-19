def solve(queries):
    results = []
    for xi, ti in queries:
        denominations = [1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000]
        denominations.sort(reverse=True)
        count = float('inf')
        ticp = ti
        for i in range(0, 50000):
            if ti < i * xi:
                break
            print(i)
            ti = ticp
            count1 = i
            ti -= i * xi
            coinsans = []
            for coins in denominations:
                #while we can still subtract coin
                while ti >= coins:
                    coinsans.append(coins)
                    ti -= coins
                    count1 += 1
            print(*denominations)
            count = min(count, count1)
        results.append(count)
        print()
    return results

Q = int(input())
queries = []

for _ in range(Q):
    xi, ti = map(int, input().split())
    queries.append((xi, ti))

results = solve(queries)

for result in results:
    print(result)