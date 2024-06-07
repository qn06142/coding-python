import turtle

def draw_square(t, D):
    for _ in range(4):
        t.forward(D)
        t.right(90)

def draw_triangle(t, D, direction):
    if direction == 'horizontal':
        for _ in range(2):
            t.forward(D)
            t.right(120)
        t.forward(D)
    else:
        t.right(60)
        for _ in range(2):
            t.forward(D)
            t.right(120)
        t.forward(D)
        t.right(60)

def draw_birthday_cake(N, D):
    t = turtle.Turtle()
    for i in range(1, N+1):
        t.penup()
        t.goto(-i*D/2, -i*D)
        t.pendown()
        for j in range(i):
            draw_square(t, D)
            t.penup()
            t.forward(D)
            t.pendown()
        t.penup()
        t.goto(-i*D/2, -i*D)
        t.pendown()
        if i % 2 == 1:  # Odd row
            for j in range(i):
                draw_triangle(t, D, 'horizontal')
                t.penup()
                t.forward(D)
                t.pendown()
        else:  # Even row
            for j in range(i):
                draw_triangle(t, D, 'vertical')
                t.penup()
                t.forward(D)
                t.pendown()

# Test the function
draw_birthday_cake(3, 50)
turtle.done()
