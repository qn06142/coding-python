with open("pointvisinp", "r") as f:
    x = []
    y = []
    for i in range(int(f.readline())):
        x.append(0)
        y.append(0)
        x[i], y[i] = [(int(i) + 1000) for i in f.readline().split()]
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(projection='3d')
for i in zip(x, y):
    ax.scatter(i[0], i[1], i[0])
plt.show()