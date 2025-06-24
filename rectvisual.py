import matplotlib.pyplot as plt
import matplotlib.patches as patches

def visualize_rectangles(rectangles):
    """
    Visualizes rectangles given as a list of (x, y, width, height) tuples.
    """
    fig, ax = plt.subplots()

    for x, y, width, height in rectangles:
        rect = patches.Rectangle((x, y), width, height, linewidth=1, edgecolor='r', facecolor='none')
        ax.add_patch(rect)

    # Set the limits of the plot to encompass all rectangles
    min_x = min(x for x, y, w, h in rectangles)
    min_y = min(y for x, y, w, h in rectangles)
    max_x = max(x + w for x, y, w, h in rectangles)
    max_y = max(y + h for x, y, w, h in rectangles)

    ax.set_xlim(min_x - 1, max_x + 1)  # Add a bit of padding
    ax.set_ylim(min_y - 1, max_y + 1)
    ax.set_aspect('equal', adjustable='box')  # Ensure the aspect ratio is equal

    plt.title('Rectangle Visualizer')
    plt.xlabel('X Axis')
    plt.ylabel('Y Axis')
    plt.grid(True)
    plt.show()

# Example Usage:
rectangles = [
    (1, 1, 5, 3),   # x, y, width, height
    (2, 2, 4, 2),
    (3, 3, 3, 1)
]

visualize_rectangles(rectangles)