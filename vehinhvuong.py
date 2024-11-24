import turtle
from random import randint

def draw_square(t, size):
    t.color(tuple(randint(0, 255) for i in range(0, 3)))
    for _ in range(4):
        t.forward(size)
        t.right(90)
    t.right(45)
    t.forward(size * (2**0.5))
    t.right(135)
    t.forward(size)
    t.right(135)
    t.forward(size * (2**0.5))
    t.right(45)

def draw_square_of_squares(t, n, d):
    for _ in range(n):
        for _ in range(n):
            draw_square(t, d)
        t.backward(n*d)
        t.right(90)
        t.forward(d)
        t.left(90)

def main():
    n = int(input())
    d = int(input())


    window = turtle.Screen()
    t = turtle.Turtle()
    window.colormode(255)
    t.speed(0)
    t.penup()
    t.setx(-window.window_width() // 2)
    t.sety(window.window_height() // 2)
    t.pendown()
    draw_square_of_squares(t, n, d)

    window.mainloop()

if __name__ == "__main__":
    main()
