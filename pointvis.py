import matplotlib.pyplot as plt

x, y = [], []
with open("pointvisinp", "r") as f:
    n = int(f.readline())
    for _ in range(n):
        px, py = map(float, f.readline().split())
        x.append(px)
        y.append(py)

plt.figure(figsize=(8, 8))
plt.scatter(x, y, c="black", s=25) 
plt.xlim(0, 10)
plt.ylim(0, 10)
plt.gca().set_aspect("equal", adjustable="box")
plt.title(f"Point Visualization ({n} points)")
plt.grid(True)
plt.show()