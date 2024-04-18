a = int(input())
b = int(input())
m = int(input())
u = (b - a + 1) // m
v = (b - a + 1 ) %m
print(int((m*(u*(u-1))//2) + u * v))