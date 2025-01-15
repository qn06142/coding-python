import cv2
import numpy as np
import time
import uinput
import ctypes

# Define the keys for the uinput device
keys = [
    uinput.KEY_LEFTSHIFT,
    uinput.KEY_SPACE,
    uinput.BTN_LEFT,
    uinput.BTN_MIDDLE,
    uinput.BTN_RIGHT,
    uinput.REL_X,
    uinput.REL_Y,
    uinput.REL_WHEEL,
    uinput.REL_HWHEEL,
    uinput.KEY_TAB,
    uinput.KEY_ENTER
]

# Create the uinput device for controlling the mouse
device = uinput.Device(keys)

# Allow the system to detect the new device
time.sleep(1)

def process_image(image_path):
    """Read the image, apply edge detection, and find contours."""
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    if img is None:
        raise FileNotFoundError(f"Image not found at {image_path}")
    kernel = np.array([
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        ], np.uint8)
    img_dilated = cv2.dilate(img, kernel, iterations=1)
    img = cv2.absdiff(img_dilated, img)
    edges = cv2.Canny(img, threshold1=100, threshold2=200)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    return contours

import ctypes
def move_mouse(x : int, y : int):
    x = ctypes.c_int(x)
    y = ctypes.c_int(y)
    device.emit(uinput.REL_X, -25000)
    device.emit(uinput.REL_Y, -25000)
    device.emit(uinput.REL_X, x)
    device.emit(uinput.REL_Y, y)
    time.sleep(0.01)
def move_mouse_relative(x, y):
    time.sleep(0.01)
    x = ctypes.c_int(x)
    y = ctypes.c_int(y)
    device.emit(uinput.REL_X, x)
    device.emit(uinput.REL_Y, y)
    time.sleep(0.01)
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
            stor.add((resized_x, resized_y))

    return resized_points

def click(x: int, y: int, btn: int = 0, count: int = 1):
    """Perform a mouse click at a specified position."""
    move_mouse(x, y)
    time.sleep(0.02)
    for _ in range(count):
        if btn == 0:
            device.emit(uinput.BTN_LEFT, 1)
            device.emit(uinput.BTN_LEFT, 0)
        elif btn == 1:
            device.emit(uinput.BTN_MIDDLE, 1)
            device.emit(uinput.BTN_MIDDLE, 0)
        elif btn == 2:
            device.emit(uinput.BTN_RIGHT, 1)
            device.emit(uinput.BTN_RIGHT, 0)
        time.sleep(0.02)

def drag_click_left(positions):
    """Drag the mouse while holding the left button along a series of positions."""
    if not positions:
        return
    time.sleep(0.01)
    move_mouse(*positions[0])
    time.sleep(0.01)
    device.emit(uinput.BTN_LEFT, 1)
    time.sleep(0.01)
    last = positions[0]
    for i, cur in enumerate(positions[1:], start=1):
        move_mouse_relative(cur[0] - last[0], cur[1] - last[1])
        last = cur
        time.sleep(0.02)
    time.sleep(0.01)
    device.emit(uinput.BTN_LEFT, 0)
from random import choice
def move_mouse_based_on_contours(image_path):
    """Move the mouse along the contours detected in an image."""
    contours = process_image(image_path)
    lines = []
    flat = []
    for contour in contours:
        points = [point[0].tolist() for point in contour]
        flat += points
        lines.append(points)
    min_x = min(point[0] for point in flat)
    max_x = max(point[0] for point in flat)
    min_y = min(point[1] for point in flat)
    max_y = max(point[1] for point in flat)
    lower, upper = (110, 110), (550, 300)

    resized_lines = [resize_points_to_rectangle(points, lower, upper, min_x, max_x, min_y, max_y) for points in lines]
    resized_lines.sort(key = len, reverse=True)
    #resized_lines = list(choice(resized_lines) for i in range(0, 500))
    resized_lines = resized_lines[:50]
    for line in resized_lines:
        drag_click_left(line)


if __name__ == "__main__":
    image_path = "/mnt/NewVolume/anime_wallpapers/stablediff1.png"  # Replace with the path to your image file

    try:
        move_mouse_based_on_contours(image_path)
    except FileNotFoundError as e:
        print(e)
    except Exception as e:
        print(f"An error occurred: {e}")