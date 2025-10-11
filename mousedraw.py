#!/usr/bin/env python3
import time
import cv2
import numpy as np
import uinput
import os

# --- Configure uinput device (adjust to your screen) ---
# Format: (min, max, fuzz, flat) - fuzz/flat usually 0.
ABS_X_RANGE = (0, 1920, 0, 0)
ABS_Y_RANGE = (0, 1080, 0, 0)

device = uinput.Device([
    uinput.ABS_X + ABS_X_RANGE,
    uinput.ABS_Y + ABS_Y_RANGE,
    uinput.BTN_LEFT,
    uinput.BTN_MIDDLE,
    uinput.BTN_RIGHT,
])

time.sleep(0.5)

def clamp(v, lo, hi):
    return max(lo, min(hi, v))

def resize_with_padding(img, target_w, target_h, pad_color=0):
    """
    Resize 'img' to fit inside (target_w, target_h) while preserving aspect ratio.
    Return (padded_image, pad_left, pad_top, scale).
    Padding is added evenly on both sides (centered).
    """
    h, w = img.shape[:2]
    if w == 0 or h == 0:
        raise ValueError("Invalid image with zero width/height")

    # compute scale to fit inside target while preserving aspect ratio
    scale = min(target_w / w, target_h / h)
    new_w = max(1, int(round(w * scale)))
    new_h = max(1, int(round(h * scale)))

    # choose interpolation: AREA for shrinking, CUBIC for enlarging
    interp = cv2.INTER_AREA if scale < 1 else cv2.INTER_CUBIC
    resized = cv2.resize(img, (new_w, new_h), interpolation=interp)

    # compute symmetric padding
    pad_left = (target_w - new_w) // 2
    pad_right = target_w - new_w - pad_left
    pad_top = (target_h - new_h) // 2
    pad_bottom = target_h - new_h - pad_top

    padded = cv2.copyMakeBorder(resized, pad_top, pad_bottom, pad_left, pad_right,
                                borderType=cv2.BORDER_CONSTANT, value=pad_color)
    return padded, pad_left, pad_top, scale

def process_image_to_screen_coords(image_path, lower, upper, preview_out="/tmp/contours_preview.png"):
    """
    Load image, resize-with-padding into rectangle lower->upper (keeps aspect ratio),
    detect contours, save a preview overlay image, and return contours as absolute coords.
    """
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    if img is None:
        raise FileNotFoundError(f"Image not found at {image_path}")

    target_w = upper[0] - lower[0]
    target_h = upper[1] - lower[1]
    if target_w <= 0 or target_h <= 0:
        raise ValueError("Invalid target rectangle (upper must be greater than lower)")

    padded, pad_left, pad_top, scale = resize_with_padding(img, target_w, target_h, pad_color=0)

    # edge enhancement similar to your original approach
    kernel = np.ones((5, 5), np.uint8)
    dil = cv2.dilate(padded, kernel, iterations=1)
    diff = cv2.absdiff(dil, padded)

    edges = cv2.Canny(diff, 100, 200)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    # convert contours to absolute screen coordinates
    abs_contours = []
    for c in contours:
        pts = []
        for p in c:
            px, py = int(p[0][0]), int(p[0][1])  # coords inside padded canvas
            abs_x = lower[0] + px
            abs_y = lower[1] + py
            abs_x = int(clamp(abs_x, ABS_X_RANGE[0], ABS_X_RANGE[1]))
            abs_y = int(clamp(abs_y, ABS_Y_RANGE[0], ABS_Y_RANGE[1]))
            pts.append((abs_x, abs_y))
        if len(pts) > 1:
            abs_contours.append(pts)

    # create a colored preview image (scale up to BGR so contours are visible)
    preview_bgr = cv2.cvtColor(padded, cv2.COLOR_GRAY2BGR)
    # shift contour internal coords back onto the padded canvas for drawing preview
    draw_contours = []
    for c in contours:
        pts = np.array([[p[0][0] , p[0][1]] for p in c], dtype=np.int32)
        draw_contours.append(pts)
    cv2.drawContours(preview_bgr, draw_contours, -1, (0, 255, 0), 1)  # green lines

    # write preview to disk
    try:
        os.makedirs(os.path.dirname(preview_out), exist_ok=True)
        cv2.imwrite(preview_out, preview_bgr)
        print(f"Saved contour preview to: {preview_out}")
    except Exception as e:
        print("Could not write preview image:", e)

    return abs_contours

def move_abs(x: int, y: int):
    device.emit(uinput.REL_X, -10 ** 9, syn=False)
    device.emit(uinput.REL_Y, -10 ** 9)
    time.sleep(0.01)
    device.emit(uinput.REL_X, int(x) //2, syn=False)
    device.emit(uinput.REL_Y, int(y) //2)
    # slight delay for kernel to process events
def drag_click_left(positions, hold_delay=0.008, step_delay=0.004):
    if not positions:
        return
    move_abs(*positions[0])
    time.sleep(hold_delay)
    device.emit(uinput.BTN_LEFT, 1)
    time.sleep(hold_delay)
    for p in positions[1:]:
        move_abs(*p)
        time.sleep(step_delay)
    time.sleep(0.004)
    device.emit(uinput.BTN_LEFT, 0)
    time.sleep(0.004)

def move_mouse_based_on_contours(image_path):
    # rectangle on screen to "draw" into (change as needed)
    lower, upper = (364, 223), (739, 498) 
    contours = process_image_to_screen_coords(image_path, lower, upper, preview_out="/tmp/contours_preview.png")
    if not contours:
        print("No contours found.")
        return

    # sort and limit contours
    contours.sort(key=len, reverse=False)
    contours = contours[50:]

    for line in contours:
        # downsample if very long
        if len(line) > 400:
            idxs = np.linspace(0, len(line) - 1, 400).astype(int)
            line = [line[i] for i in idxs]
        drag_click_left(line)

if __name__ == "__main__":
    time.sleep(1)
    IMAGE_PATH = "/mnt/NewVolumne/anime_wallpapers/koishi.jpg"  # change as needed
    try:
        move_mouse_based_on_contours(IMAGE_PATH)
    except FileNotFoundError as e:
        print(e)
    except Exception as e:
        print("Error:", e)
