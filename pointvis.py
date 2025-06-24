with open("pointvisinp", "r") as f:
    x = []
    y = []
    for i in range(int(f.readline())):
        x.append(0)
        y.append(0)
        x[i], y[i] = [(int(i)) for i in f.readline().split(sep=',')]
import matplotlib.pyplot as plt
import numpy as np
grid = np.zeros((71, 71), dtype=int)
for x, y in zip(x, y):
    grid[y][x] = 1
plt.imshow(grid, cmap='Greys', origin='lower')
plt.title('Binary Grid (1 = Point, 0 = Empty)')
plt.grid(True)
plt.show()