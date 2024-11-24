n = int(input())
a, b = 1, 1
ys = []
for i in range(0, n):
    c = a + b
    a = b
    b = c
    ys.append(c  % 100)
import matplotlib.pyplot as plt

xs = [x for x in range(len(ys))]

plt.plot(xs, ys)
plt.show()