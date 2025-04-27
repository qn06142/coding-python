import wave
import sys

import pyaudio
import random

CHUNK = 1024

p = pyaudio.PyAudio()

stream = p.open(format=p.get_format_from_width(1),
                channels=1,
                rate=20000,
                output=True)
while True:
    samp = bytes(random.sample([0, 255], 1))
    print(samp)
    stream.write(samp)
stream.close()
p.terminate()