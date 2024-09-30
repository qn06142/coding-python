import matplotlib.pyplot as plt
import matplotlib.patches as patches

def visualize_rectangles(rectangles):
    """
    Visualize a set of rectangles in a 2D grid using matplotlib.
    
    rectangles: List of tuples (t, x, y) where:
        t: starting x position
        x: end x position (width of the rectangle)
        y: height of the rectangle
    """
    fig, ax = plt.subplots()
    
    # Set the figure size
    ax.set_xlim(0, 20)  # Change the limit to your expected range of x coordinates
    ax.set_ylim(0, 15)  # Change the limit to your expected range of y coordinates
    
    # Plot each rectangle
    for rect in rectangles:
        t, x, y = rect
        width = x - t
        height = y
        ax.add_patch(patches.Rectangle((t, 0), width, height, linewidth=1, edgecolor='r', facecolor='blue', alpha=0.3))
        ax.text(t + width / 2, height / 2, f'({t},{x},{y})', ha='center', va='center', fontsize=10, color='black')
    
    # Labels and titles
    plt.xlabel('X-axis (t, x)')
    plt.ylabel('Y-axis (height)')
    plt.title('Rectangle Visualizer')
    
    plt.grid(True)
    plt.show()

# Example usage:
if __name__ == "__main__":
    # Input the number of rectangles and their (t, x, y) coordinates
    rectangles = [
        tuple(int(i) for i in input().split()) for i in range(0, int(input()))
    ]
    
    visualize_rectangles(rectangles)
