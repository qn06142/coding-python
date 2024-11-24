testcases = [[int(i) for i in input().split()] for i in range(0, int(input()))]
grer = "X > Y"
smer = "X < Y"
eqal = "X = Y"
for test in testcases:
    if test[1] == test[3]:
        if test[0] > test[2]:
            print(grer)
        if test[0] < test[2]:
            print(smer)
        if test[0] == test[2]:
            print(eqal)
    elif test[1] > test[3]:
        print(grer)
    elif test[1] < test[3]:
        print(smer)

