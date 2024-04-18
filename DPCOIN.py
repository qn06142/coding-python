from fractions import Fraction
for i in range(0, int(input())):
	n, x = tuple(int(i) for i in input().split())
	a = [0] + [Fraction(i) for i in input().split()]
	f = [Fraction(0)] * (n + 5)
	f[0] = Fraction(x)
	for i in range(1, n + 1):
		f[i] = f[i-1]
		for j in range(i - 1, 0, -1):
			f[i] = max(f[i], f[j - 1] * (a[i] / a[j]) - f[j - 1] / Fraction(50))
	print("%.5f" % f[n])