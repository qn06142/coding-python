import gzip
import base64
with open("csphn_flipans.out", "r") as f:
    file = f.read().splitlines()
with open("csphn_flipanscomp.out", "w") as f:
    f.write(base64.b64encode(gzip.compress(' '.join(i.split()[1] for i in file).encode(), compresslevel=9)).decode())