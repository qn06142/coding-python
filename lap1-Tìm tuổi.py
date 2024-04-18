inp = int(input())
cases = []
cases = [input().split() for i in range(0, inp)]
for i in cases:
    ages = i
    father = int(ages[0])
    son = int(ages[1])
    yes = 0
    while not father/2 == son and yes <= 10**6:
        father += 1
        son += 1
        yes += 1
    if not yes == 10**6+1:
        print(yes)
    else:
        print(-1)
