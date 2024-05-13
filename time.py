from time import time
speed = time() - time()
iters = 0
while True:
    curr = time()
    iters += 1
    if iters % 10 == 0:
        iters = 0
        print(speed)
    yes = '0' * 1000000000
    speed = (speed + time() - curr) / 2
