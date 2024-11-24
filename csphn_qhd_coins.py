def count_ways_and_min_coins(n):

    squares = [i ** 2 for i in range(1, 101)]

    dp_ways = [0] * (n + 1)
    dp_ways[0] = 1  

    for square in squares:
        for j in range(square, n + 1):
            dp_ways[j] += dp_ways[j - square]

    dp_min_coins = [float('inf')] * (n + 1)
    dp_min_coins[0] = 0  

    for square in squares:
        for j in range(square, n + 1):
            dp_min_coins[j] = min(dp_min_coins[j], dp_min_coins[j - square] + 1)

    print(n % 123456789)
    print(dp_min_coins[n])

n = int(input())
count_ways_and_min_coins(n)