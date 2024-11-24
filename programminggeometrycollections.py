from math import acos, sqrt
#angle between two vect to (0, 0)
def angle_between(a, b):
	dotprod = a[0]*b[0] + a[1]*b[1]
	maga = sqrt(a[0] ** 2 + a[1] ** 2)
	magb = sqrt(b[0] ** 2 + b[1] ** 2)
	return acos(dotprod/(maga*magb))
# Example usage
def testanglebetween():
	v1 = tuple(int(i) for i in input().split())
	v2 = tuple(int(i) for i in input().split())
	print(angle_between(v1,v2))
#distance between two vects
from math import acos, sqrt
def distance_between(a,b):
	return sqrt(abs(a[0]-b[0]) ** 2 + abs(a[1]-b[1]) ** 2)
v1 = tuple(int(i) for i in input().split())
a = (v1[0], v1[1])
b = (v1[2], v1[3])
print(distance_between(a,b))