import os
import numpy as np
from PIL import Image
for fontname in os.listdir('font'):
    filename = fontname
    fontname = "/run/media/wheatley/NewVolume/coding python/vmvsos/font/" + fontname
    with open(fontname, "r") as f:
        m, n = tuple(int(i) for i in f.readline().split())
        arr = np.array([[255 if i == '#' else 0 for i in f.readline().strip()] for _ in range(n)], dtype=np.uint8)

    #print(*arr, sep="\n", file=open("test.out", "w"))

    img = Image.fromarray(arr, "L")
    img.save("images/" + filename + ".jpeg")
