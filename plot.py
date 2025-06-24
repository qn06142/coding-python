import matplotlib.pyplot as plt
import numpy as np

def plot_functions(functions, x_start=-1000, x_end=1000, num_points=1000):
    """
    Plots one or more single-variable functions over the range [x_start, x_end].

    Parameters:
    - functions: A list of functions to plot (each takes a single argument).
    - x_start: Start of the x-axis range.
    - x_end: End of the x-axis range.
    - num_points: Number of points to plot.
    """
    x = np.linspace(x_start, x_end, num_points, dtype=int)

    plt.figure(figsize=(10, 6))
    for f in functions:
        y = f(x)
        name = getattr(f, "__name__", "anonymous")
        plt.plot(x, y, label=name)

    plt.title("Plot of Function(s)")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.show()

import random
a = [random.randint(0, 10000) for _ in range(1000)]
med = sum(abs(i - sorted(a)[len(a)//2]) for i in a)
def calc(cnt0):
    return sum(abs(cnt0 - i) for i in a)

def square(x):
    return np.full_like(x, med)

if __name__ == "__main__":
    plot_functions([calc, square], x_start=min(a), x_end=max(a))