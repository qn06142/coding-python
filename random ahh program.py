print("program one")
import turtle
for i in range(0, 4):
	turtle.forward(100)
	turtle.left(90)
input("press enter to continue")
print("program two")
print("area:" + str(int(input("please enter the edge length:"))))
input("press enter to continue")
print("program three")
print("is even" if int(input("please enter your number")) % 2 == 0 else "is odd")