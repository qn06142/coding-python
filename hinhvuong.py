from turtle import *
from random import randint
colormode(255)
def randcolor():
    return tuple(randint(0, 255) for i in range(0, 3))
#center
penup()
backward(100)
left(90)
backward(100)
pendown()
#draw square
for _ in range(0, 4):
    forward(200)
    right(90)
color(randcolor())
forward(100)
begin_fill()
forward(100)
right(90)
forward(100)
right(90 + 45)
forward(142)
end_fill()
for _ in range(0, 3):
    color(*randcolor())
    backward(142)
    left(45 + 90)
    begin_fill()
    forward(100)
    right(90)
    forward(100)
    right(90 + 45)
    forward(142)
    end_fill()
'''
try:
    while True:
        exec(input())
except KeyboardInterrupt:
    pass
'''