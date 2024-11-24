x = 562108
n = int(input())
d = 1
du = x % n
while du > 0:
	d += 1
	du = (du * 1000000 + x) % n
print(d * 6)