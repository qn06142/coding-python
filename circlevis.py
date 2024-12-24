import matplotlib.pyplot as plt
import numpy as np

# Function to plot circles
def plot_circles(circles):
    fig, ax = plt.subplots()
    
    for circle in circles:
        # Extract circle parameters (x, y, diameter)
        x, y, diameter = circle
        radius = diameter / 2
        
        # Create a circle and add it to the plot
        circle_patch = plt.Circle((x, y), radius, edgecolor='blue', facecolor='none', lw=2)
        ax.add_patch(circle_patch)
    
    # Set the limits of the plot to make sure all circles fit
    ax.set_aspect('equal', 'box')
    ax.set_xlim(-10, 110)
    ax.set_ylim(-10, 110)
    
    plt.title("Circles Plot")
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.grid(True)
    plt.show()

n = int(input())
circle = []
for i in range(0, n):
    x, r = map(int, input().split())
    circle.append((x, 0, r * 2));
# Plot the circles
plot_circles(circle)
