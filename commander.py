import socket
import cv2
import numpy as np
import math
from vidgear.gears import CamGear
import random
import time
host = '127.0.0.1'
port = 8000
while True:
    try:
        server_socket = socket.socket(socket.SO_REUSEADDR, socket.SOCK_STREAM)
        server_socket.bind((host, port))
        server_socket.listen(5)
    except OSError:
        print("no port, retrying")
        time.sleep(1)
    else:
        print("got port, listening on", port)
        break
def clear_line(n=1):
    LINE_UP = '\033[1A'
    LINE_CLEAR = '\x1b[2K'
    for i in range(n):
        print(LINE_UP, end=LINE_CLEAR)
def colorReduce(image, div=64):
    nl, nc = image.shape[:2]
    
    # Loop through each row
    for j in range(nl):
        # Loop through each column of the row
        for i in range(nc):
            # Process each pixel
            image[j, i] = (image[j, i] // div) * div + div // 2
    return image


def resize_image_to_fit(img, target_width, target_height):
    """Resize the image to fit the target aspect ratio."""
    h, w = img.shape[:2]
    scale = min(target_height / h, target_width / w)
    h, w = math.ceil(h * scale), math.ceil(w * scale)
    return cv2.resize(img, (w, h))
options = {"STREAM_RESOLUTION": "best"}
path = "https://www.youtube.com/watch?v=PshZOi3VsJU"
vid = CamGear(source=path, stream_mode="http" in path, backend=cv2.CAP_GSTREAMER, logging=True, **options).start()
count = 0
soc, addr = server_socket.accept()
target_width, target_height = 160, 100
frame = vid.read()
ref = np.zeros(resize_image_to_fit(frame, target_width, target_height).shape)
target_width, target_height = ref.shape[1], ref.shape[0]
soc.sendall(f"RESO {target_width} {target_height / 2}".encode())
def get_diff_pixels(ref_img, curr_img):
    diff_mask = np.abs(ref_img.astype(np.int16) - curr_img.astype(np.int16)) >= 20
    diff_indices = np.argwhere(np.any(diff_mask, axis=-1))  # Coordinates of differing pixels
    diff_values = curr_img[diff_mask.any(axis=-1)]         # Pixel values at differing coordinates

    # Update reference image for these differing pixels
    for (y, x), new_val in zip(diff_indices, diff_values):
        ref_img[y, x] = new_val

    return diff_indices, diff_values, ref_img
buff = ""
colred = 16
def colorcrush(r, g, b):
    return tuple(math.floor(i / colred) * colred for i in (r, g, b))
def rgbtohex(red, green, blue):
    red = int(red)
    green = int(green)
    blue = int(blue)
    red, green, blue = colorcrush(red, green, blue)
    return (red) + (green * 256) + blue * 256 * 256
def draw(x, y, col, count):
    global buff
    message = ('DRAW ' + ' '.join(str(i) for i in (x, y, col)))
    buff += message
def flushbuffer():
    global buff
    soc.sendall(buff.encode())
    buff = ""
    soc.sendall('FLSH'.encode())
def waitflush():
    stat = soc.recv(4)
    if stat.decode() == "DONE":
        return True
    return False
import time
import cv2
#
#cur = time.time()
#print("target: ", vid.framerate)
#frame = vid.read()
#
#frame_resized = resize_image_to_fit(frame, target_width, target_height)
#diff_indices, diff_values, ref = get_diff_pixels(ref, frame_resized)
#
#for (y, x), (col) in zip(diff_indices, list(rgbtohex(*i) for i in diff_values)):
#    draw(x, y, col, count)
#    count += 1
#flushbuffer()
#
while True:
    frame_start_time = time.time()
    
    frame = vid.read()
    if frame is None:
        break

    frame_resized = resize_image_to_fit(frame, target_width, target_height)
    diff_indices, diff_values, ref = get_diff_pixels(ref, frame_resized)
    vals = list(zip(diff_indices, list(rgbtohex(*i) for i in diff_values)))

    for (y, x), (col) in vals:
        draw(x, y, col, count)
        count += 1
    flushbuffer()

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

    frame_end_time = time.time()
    frame_processing_time = frame_end_time - frame_start_time
    target_frame_time = 1.0 / vid.framerate

    # Wait for the remaining time if processing was faster than target frame time
    time_to_wait = target_frame_time - frame_processing_time
    if time_to_wait > 0:
        time.sleep(time_to_wait)

    actual_framerate = 1 / (time.time() - frame_start_time)
    error_rate = actual_framerate - vid.framerate

    clear_line(1)
    print(f"Actual FPS: {actual_framerate:.2f}, Error Rate: {error_rate:.2f}")
soc.sendall("END")
soc.recv(3)