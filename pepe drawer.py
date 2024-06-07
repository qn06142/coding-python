from turtle import *
from random import randint
speed(10)
colormode(255)
s = textinput("", "pls input pepe name")
size = numinput("", "pls input pepe size in percents (more than 100)")
charheight = 10 * (size / 100)
stringlen = len(s) * 6 * (size / 100)
def drawstring():
    color(tuple(randint(0, 255) for i in range(0, 3)))
    penup()
    write(s, move=False, align='left', font=('Arial', int(8 * (size / 100)), 'normal')) 
def drawball():
    penup()
    for _ in range(0, int(stringlen/charheight)):
        drawstring()
        right(90)
        forward(int(10 * (size/100)))
        left(90)
def drawstick():
    for _ in range(0, 3):
        forward(stringlen)
        drawball()
        left(90)
        forward(int(stringlen/charheight) * charheight)
        right(90)

drawball()
drawstick()
home()
right(90)
forward(2 * charheight * (int(stringlen/charheight)))
left(90)
drawball()
mainloop()