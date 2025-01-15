import cv2
import numpy as np
import tkinter as tk
from tkinter import Canvas
import random
import time
import imgutils.edge as edge
from PIL import Image
def process_image(img, target_width, target_height):
    """Read the image, resize it to the target aspect ratio, apply edge detection, and find contours."""

    img_resized = resize_image_to_fit(img, target_width, target_height)
    img_gray = img_resized
    #img_gray = cv2.cvtColor(img_resized, cv2.COLOR_BGR2RGB)
    #img_gray = cv2.GaussianBlur(src=img_gray, ksize=(3, 5), sigmaX=0.5) 
    img_gray = Image.fromarray(img_gray)
    im_np = edge.canny.edge_image_with_canny(img_gray)
    im_np = np.asarray(im_np)

    if len(im_np.shape) == 3:  
        im_np = cv2.cvtColor(im_np, cv2.COLOR_RGB2GRAY)

    thresh = cv2.adaptiveThreshold(
        im_np, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 21, 15
    )
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_TC89_L1)   
    return img_resized.shape, contours

import math
def resize_image_to_fit(img, target_width, target_height):
    """Resize the image to fit the target aspect ratio."""
    h, w = img.shape[:2]
    scale = min(target_height / h, target_width / w)
    h = h * scale
    w = w * scale
    h = math.ceil(h)
    w = math.ceil(w)

    resized_img = cv2.resize(img, (w, h))
    return resized_img

def resize_points_to_rectangle(points, lower, upper, min_x, max_x, min_y, max_y):
    """Resize points to fit within a rectangle defined by lower and upper."""
    if not points:
        return []

    resized_points = []
    stor = set()
    for point in points:
        resized_x = lower[0] + (point[0] - min_x) * (upper[0] - lower[0]) // max(1, (max_x - min_x))
        resized_y = lower[1] + (point[1] - min_y) * (upper[1] - lower[1]) // max(1, (max_y - min_y))
        if (resized_x, resized_y) not in stor:
            resized_points.append((resized_x, resized_y))
            stor.append((resized_x, resized_y))

    return resized_points

mul = 2
colp = 1
def pixfy(x):
    return x // mul * mul

def pixfy1(x):
    return math.ceil(x / mul + 0.1) * mul

def _from_rgb(rgb):
    """Convert RGB tuple to Tkinter-friendly color code."""
    if type(rgb) == np.ndarray:
        rgb = tuple(rgb.tolist())
    return "#%02x%02x%02x" % rgb

def area(x, y, u, v):
    return abs(x - u) * abs(y - v)
from concurrent.futures import ThreadPoolExecutor
def average(cola, colb):
    return tuple((cola[i] + colb[i]) // 2 for i in range(0, 3))
def roundcol(col, mean):
    return tuple(col[i] // colp * colp if col[i] < mean[i] else math.ceil(col[i] / colp) * colp for i in range(0, 3))
def draw_line(canvas, line, frame, meancol):
    sz = 0
    for i in range(1, len(line)):
        x = tuple(pixfy(coord) for coord in line[i - 1])
        y = tuple(pixfy1(coord) for coord in line[i])
        #col = tuple(random.randint(0, 255) for _ in range(3))[::-1]
        
        col = average(frame[line[i][1]][line[i][0]].tolist(), frame[line[i - 1][1]][line[i - 1][0]].tolist())
        col = roundcol(col, meancol)
        #cv2.rectangle(canvas, x, y, col, cv2.FILLED)
        cv2.line(canvas, x, y, col, thickness=mul * mul)
        sz += 1
    return sz

def draw_lines_on_canvas(canvas, contours, lower, upper, canvas_width, canvas_height, frame, meancol):
    sz = 0
    contours = [[point[0].tolist() for point in contour] for contour in contours]
    for i in contours:
        sz += draw_line(canvas, i, frame, meancol)
    return sz

import cv2
import numpy as np
from multiprocessing import Process, Queue

def process_frame_worker(frame_queue, result_queue, canvas_width, canvas_height):
    """Worker function to process frames."""
    while True:
        item = frame_queue.get()
        if item is None:
            return
        frame_index, frame = item
        if frame is None:
            return
        
        frame = resize_image_to_fit(frame, canvas_width, canvas_height)
        dim, contours = process_image(frame, canvas_width, canvas_height)
        average_color = np.mean(frame, axis=(0, 1))
        #canvas = np.full_like(frame, average_color, dtype=frame.dtype)
        canvas = np.zeros((canvas_height, canvas_width, 3), dtype=np.uint8)
        #canvas = np.copy(rand)
        lower, upper = (0, 0), dim[::-1]
        tmp = time.time()
        sz = draw_lines_on_canvas(canvas, contours, lower, upper, canvas_width, canvas_height, frame, average_color)
        result_queue.put((frame_index, dim, canvas, sz))
def clear_line(n=1):
    LINE_UP = '\033[1A'
    LINE_CLEAR = '\x1b[2K'
    for i in range(n):
        print(LINE_UP, end=LINE_CLEAR)
        
import faulthandler
import signal
faulthandler.register(signal.SIGUSR1.value)
import collections
canvas_width, canvas_height = 1024, 576
num_workers = 16

rng = np.random.default_rng()
from scipy.ndimage import gaussian_filter
rand = rng.uniform(0, 255, size=(canvas_height + 1, canvas_width + 1, 3))
rand = rand.astype(np.uint8)

frame_queue = Queue()
result_queue = Queue()

workers = []
for _ in range(num_workers):
    worker = Process(target=process_frame_worker, args=(frame_queue, result_queue, canvas_width, canvas_height))
    worker.start()
    workers.append(worker)
from vidgear.gears import CamGear, WriteGear
options = {"STREAM_RESOLUTION": "480p", "STREAM_PARAMS" : {"allow_file_urls" : True}}
vid = CamGear(source='https://www.youtube.com/watch?v=QPZN8lxD7bc', stream_mode=True, backend=cv2.CAP_GSTREAMER, logging=True, **options).start()
#if not vid.isOpened():
#    print("uhh video weird")
#    raise ValueError
fps = vid.framerate
print("target:", fps)
print("\n\n\n\n")
output_params = {"-input_framerate" : fps}
writer = WriteGear(output="Output.mp4", **output_params)
begin = time.time()
frametime = 1 / fps
rate = frametime
frame_index = 0
processed_frames = collections.defaultdict(tuple)
timestamp = time.time()
process_frame = 0
errorrate = 0
for _ in range(0, num_workers):
    frame = vid.read()
    if frame is None:
        break

    frame_queue.put((process_frame, frame))
    process_frame += 1

while True:
    if not result_queue.empty():
        idx, dim, canvas, size = result_queue.get()
        processed_frames[idx] = (dim, canvas, size)

    if processed_frames[frame_index]:
        if time.time() - timestamp > rate:
            errorrate = frame_index - math.ceil(fps * (time.time() - begin))
            corrtype = ''
            if abs(errorrate) >= 2:
                rate = 1 / (fps + -errorrate * 100)
                corrtype = 'coarse'
            else:
                rate = 1 / (fps + -(frame_index - (fps * (time.time() - begin))))
                corrtype = 'fine'
            dim, canvas, sz = processed_frames.pop(frame_index)
            clear_line(6)
            print("error:", errorrate)
            print(rate)
            print(sz)
            print("fps:", (frame_index + 1)/ (time.time() - begin))
            print(corrtype)
            print(len(processed_frames), process_frame, frame_queue.qsize())
            #cv2.imshow("vid", resize_image_to_fit(canvas, 512, 268))
            cv2.imshow("vid", canvas)
            writer.write(canvas)
            frame_index += 1
            timestamp = time.time()
            frame = vid.read()
            if frame is None:
                break

            frame_queue.put((process_frame, frame))
            process_frame += 1

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

vid.stop()
writer.close()

cv2.destroyAllWindows()
cnt = 0

while frame_queue.qsize() > 0:
    print("waiting for frame queue", frame_queue.qsize())
    frame_queue.get()
    clear_line(1)
for _ in workers:
    frame_queue.put(None)  
while result_queue.qsize() > 0:
    result_queue.get()
for worker in workers:
    print("term:", cnt)
    print(result_queue.qsize())
    clear_line(2)
    cnt += 1
    worker.terminate()