from vidgear.gears import CamGear
import cv2
options = {"STREAM_RESOLUTION": "480p", "STREAM_PARAMS" : {"allow_file_urls" : True}}
vid = CamGear(source='https://www.youtube.com/watch?v=QPZN8lxD7bc', stream_mode=True, backend=cv2.CAP_GSTREAMER, logging=True, **options).start()

while True:
    frame = vid.read()
    if frame is None: break
    frame32 = cv2.cvtColor(frame, cv2.COLOR_BGR2BGRA)
    fbframe = cv2.resize(frame32, (1920,1080))
    with open('/dev/fb0', 'rb+') as buf:
        buf.write(fbframe)
    print("done")