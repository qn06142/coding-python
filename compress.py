import cv2
import numpy as np
import math
import struct


def resize_image_to_fit(img, target_width, target_height):
    """Resize the image to fit the target aspect ratio."""
    h, w = img.shape[:2]
    scale = min(target_height / h, target_width / w)
    new_h, new_w = math.ceil(h * scale), math.ceil(w * scale)
    return cv2.resize(img, (new_w, new_h))


def _encode_quadtree(img, x, y, size, rects):
    """
    Recursively decompose img[y:y+size, x:x+size] into uniform-color blocks.
    """
    block = img[y:y+size, x:x+size]
    if np.all(block == block[0, 0]):
        color = int(block[0, 0] == 255)
        rects.append((x, y, size, size, color))
    else:
        half = size // 2
        if half == 0:
            color = int(block[0, 0] == 255)
            rects.append((x, y, 1, 1, color))
        else:
            for dy in (0, half):
                for dx in (0, half):
                    _encode_quadtree(img, x + dx, y + dy, half, rects)


def image_to_rectangles(image, thresh=127):
    """
    Convert a single-channel (grayscale) OpenCV image into quadtree rectangles.
    Returns: list of (x, y, w, h, color).
    """
    _, binary = cv2.threshold(image, thresh, 255, cv2.THRESH_BINARY)
    h, w = binary.shape
    size = 1 << max(h, w).bit_length()
    padded = np.zeros((size, size), dtype=binary.dtype)
    padded[:h, :w] = binary

    rects = []
    _encode_quadtree(padded, 0, 0, size, rects)
    return [r for r in rects if r[0] < w and r[1] < h]


def compress_frame_to_rects(frame, thresh=127):
    """
    Split a BGR frame into per-channel quadtree rectangles.
    Returns dict {'B': [...], 'G': [...], 'R': [...]}.
    """
    chans = cv2.split(frame)
    return {name: image_to_rectangles(chans[i], thresh)
            for i, name in enumerate(('B','G','R'))}


def write_rects_binary(fp, rects_by_channel):
    """
    Write channels to binary file:
      - 1 byte: 'R','G','B'
      - 4 bytes: uint32 LE count
      - per rect: uint16 x,y,w,h and uint8 color
    """
    for ch in ('R','G','B'):
        rects = rects_by_channel[ch]
        fp.write(ch.encode('ascii'))
        fp.write(struct.pack('<I', len(rects)))
        for x, y, w, h, c in rects:
            fp.write(struct.pack('<HHHHB', x, y, w, h, c))


if __name__ == '__main__':
    video_path = '/home/wheatley/badapple.mp4'
    cap = cv2.VideoCapture(video_path)
    if not cap.isOpened():
        raise IOError(f"Cannot open video: {video_path}")

    with open('rectangles.bin', 'wb') as f:
        while True:
            ret, frame = cap.read()
            if not ret:
                break
            frame = resize_image_to_fit(frame, 160, 50)
            rects = compress_frame_to_rects(frame)
            write_rects_binary(f, rects)
            cv2.imshow('Video Stream', frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
    cap.release()