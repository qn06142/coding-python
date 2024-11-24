import turtle
import math

# Initialize the screen and turtle
screen = turtle.Screen()
screen.title("Turtle Operations")
t = turtle.Turtle()
t.penup()

# Draw the x and y axes
t.goto(-300, 0)
t.pendown()
t.goto(300, 0)
t.penup()
t.goto(0, -300)
t.pendown()
t.goto(0, 300)

# Initialize the set S
S = []

# Function to add point (x, y) to set S
def add_point(x, y):
    S.append((x, y))
    t.goto(x, y)
    t.dot(5, "blue")  # Mark the point on the screen

# Function to find the point farthest from set S
def farthest_point():
    if not S:
        return None
    max_distance = -1
    farthest = None
    for point in S:
        distance = math.sqrt(point[0]**2 + point[1]**2)
        if distance > max_distance:
            max_distance = distance
            farthest = point
    return farthest

for i in range(0, int(input())):
    add_point(*(int(i) * 100 for i in input().split()))

farthest = farthest_point()
if farthest:
    t.goto(farthest)
    t.dot(10, "red")  # Highlight the farthest point

turtle.done()
