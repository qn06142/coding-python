from math import factorial as fact
n = input().split()
for i in range(0, 3):
    n[i] = int(n[i])
print(int(fact(n[1])/fact(n[0]-1)%11))
