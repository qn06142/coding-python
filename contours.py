import cv2
import numpy as np
import tkinter as tk
from tkinter import Canvas
import random
import time
import imgutils.edge as edge
from PIL import Image
def process_image(
    img: np.ndarray, 
    target_width: int, 
    target_height: int):

    img_resized = resize_image_to_fit(img, target_width, target_height)
    
    # Step 2: Apply specialized edge detection.
    # The 'edge' library requires a PIL Image, so we convert from a NumPy array.
    edge_detected_img = edge.edge_image_with_lineart_anime(Image.fromarray(img_resized))
    edge_detected_np = np.asarray(edge_detected_img)

    # Step 3: Ensure the image is single-channel (grayscale) for contour detection.
    # The edge detection might return an RGB image, so we convert if necessary.
    if len(edge_detected_np.shape) > 2 and edge_detected_np.shape[2] == 3:
        gray_image = cv2.cvtColor(edge_detected_np, cv2.COLOR_RGB2GRAY)
    else:
        gray_image = edge_detected_np

    # Step 4: Create a binary mask from the grayscale image.
    # cv2.THRESH_BINARY_INV makes the detected lines (objects) white and background black.
    # cv2.THRESH_OTSU automatically calculates the optimal threshold value from the image.
    # The first argument (the threshold value) is ignored when using OTSU, so we use '_' 
    # to indicate it's an intentionally unused variable.
    _, binary_mask = cv2.threshold(
        gray_image, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU
    )

    # Step 5: Find contours in the binary mask.
    # cv2.RETR_EXTERNAL retrieves only the outermost contours (ignores holes).
    # cv2.CHAIN_APPROX_TC89_KCOS is an efficient algorithm for compressing contour points.
    contours, _ = cv2.findContours(
        binary_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_TC89_KCOS
    )   
    
    return img_resized.shape, contours

import math
import cv2
import numpy as np

def resize_image_to_fit(img: np.ndarray, target_width: int, target_height: int) -> np.ndarray:
    # Get original image dimensions
    original_h, original_w = img.shape[:2]

    # Calculate the ratio to scale the image
    # The image will be scaled down to fit completely inside the target dimensions.
    ratio = min(target_width / original_w, target_height / original_h)

    # Calculate new dimensions, ensuring they are integers
    new_w = int(original_w * ratio)
    new_h = int(original_h * ratio)

    # Resize the image using the calculated dimensions
    # cv2.INTER_AREA is recommended for shrinking images
    resized_img = cv2.resize(img, (new_w, new_h), interpolation=cv2.INTER_AREA)

    return resized_img
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
        #col = roundcol(col, meancol)
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
canvas_width, canvas_height = 1000, 1000
num_workers = 6

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
#vid = CamGear(source="/mnt/NewVolumne/lofi/sumeru lo-fi beats to do dailies with (genshin impact) [EQyTz7dS6yw].webm",
#    stream_mode=False, backend=cv2.CAP_INTEL_MFX , logging=True).start()
vid = cv2.VideoCapture("/run/media/wheatley/1d28986e-422c-47fc-8f9c-28e84ac03b0a/collection/51.Ningguang (audio update) 1080p.mp4")
#if not vid.isOpened():
#    print("uhh video weird")
#    raise ValueError
try:
    fps = vid.framerate
except:
    fps = vid.get(cv2.CAP_PROP_FPS)
print("target:", fps)
print("\n\n\n\n")
output_params = {"-input_framerate" : fps}
#writer = WriteGear(output="Output.mp4", **output_params)
begin = time.time()
frametime = 1 / fps
rate = frametime
frame_index = 0
processed_frames = collections.defaultdict(tuple)
timestamp = time.time()
process_frame = 0
errorrate = 0
for _ in range(0, num_workers):
    _, frame = vid.read()
    if _ is False:
        break

    frame_queue.put((process_frame, frame))
    process_frame += 1
try:
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
                cv2.imshow("vid", resize_image_to_fit(canvas, 512, 268))
                #cv2.imshow("vid", canvas)
                #writer.write(canvas)
                frame_index += 1
                timestamp = time.time()
                _, frame = vid.read()
                if _ is False:
                    break

                frame_queue.put((process_frame, frame))
                process_frame += 1

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
finally:
    #writer.close()

    cv2.destroyAllWindows()
    cnt = 0
    for _ in workers:
        frame_queue.put(None)  
    for worker in workers:
        print("term:", cnt)
        print(result_queue.qsize())
        clear_line(2)
        cnt += 1
        worker.terminate()