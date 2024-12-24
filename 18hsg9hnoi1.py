n = int(input())
from math import *
import base64
import gzip
from sys import exit
primes = set(eval(gzip.decompress(base64.b64decode("H4sIAOhhWWcC/yWS23XFMAgEW3EB/rB4CKglJ/23EWbzESShm/Huoh97H3+ffJ96n3P2b0+H/byP7d529e379mLX2F7sPvmvvbvbu3uuXWt7tb3etXcdOB/QD+qn4/AdjsbR9UntuAhK0kt6l99BPyVZ3Da3o0JP3xjEot4kGbKZDHCEbGi3VOEWsl0uEG5FD7K1PG9x5DpQR64TiisJ5HqoEA5JOFE4Sh2ljlIH5eTgiAyCCOwH2YYpTBUiRWQoXKCByCDbQGlADqDR7LAfmE6CTaAJL7GfWE3NCEoCSKwmVhOrCSVHI2SGSLv4vVi9Rzsu0HdDhQugF79Xo/+fPUegF78XafWpDK+CwjwKl4XLAlWMotBXUAp9pfeDtCKwBtAMoE2FVwWqTW+MgpaG0ghqrDZamlm23iG8wduAGgQNgGGMg7fB1oAach5iGigDYHA0U79/JfX88ysDAAA="))))
def check(n):
    return n in primes
while True:
    n += 1
    if check(sum(int(i) ** 2 for i in str(n))):
        print(n)
        exit(0)
