x = int(input())
for i in range(1, x):
    divisors = []
    for j in range(1, i):
        if i % j == 0:
            divisors.append(j)
        if sum(divisors) == j and sum([x for x in range(1, j) if j % x == 0]) == i:
            print(str(i) + " " + str(j))
