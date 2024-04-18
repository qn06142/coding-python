from os import system
def clear():
	system('cls')
board = [['#' for i in range(0, 10)] for j in range(0, 10)]
currpos = [1, 1]
inp = ""
def printf(a):
	for i in a:
		print(''.join(i))
while inp != 'exit':
	inp = input("move:")
	if inp == "u" and currpos[0] >0:
		board[currpos[0]][currpos[1]] = '#'
		currpos[0] += 1
		board[currpos[0]+1][currpos[1]] = '0'
	if inp == "d" and currpos[0] <10:
		board[currpos[0]][currpos[1]] = '#'
		currpos[0] -= 1
		board[currpos[0]-1][currpos[1]] = '0'
	if inp == "l" and currpos[1] >0:
		board[currpos[0]][currpos[1]] = '#'
		currpos[1] -= 1
		board[currpos[0]][currpos[1]] = '0'
	if inp == "u" and currpos[1] <0:
		board[currpos[0]][currpos[1]] = '#'
		currpos[1] += 1
		board[currpos[0]][currpos[1]] = '0'
	printf(board)