import numpy as np
import cv2
import math
import time

def decompress_rle_columns_with_colors(rle_columns, rows):
    """
    Decompress RLE-encoded columns into an array for a single color channel.
    """
    decompressed_channel = np.zeros(rows, dtype=np.uint8)
    row_idx = 0
    for value, length in rle_columns:
        decompressed_channel[row_idx:row_idx + length] = value
        row_idx += length
    return decompressed_channel

def read_rle_file(file_path):
    """
    Read an RLE file and parse it into frames with R, G, and B channels.
    """
    with open(file_path, 'r') as f:
        lines = f.readlines()

    rows, cols = map(int, lines[0].strip().split())

    frames = []
    for i in range(1, len(lines), cols * 3):
        frame = []
        for j in range(i, i + cols * 3, 3):
            r_channel = list(zip(map(int, lines[j].split()[::2]), map(int, lines[j].split()[1::2])))
            g_channel = list(zip(map(int, lines[j + 1].split()[::2]), map(int, lines[j + 1].split()[1::2])))
            b_channel = list(zip(map(int, lines[j + 2].split()[::2]), map(int, lines[j + 2].split()[1::2])))
            frame.append([r_channel, g_channel, b_channel])
        frames.append(frame)

    return frames, rows, cols

def resize_image_to_fit(img, target_width, target_height):
    """Resize the image to fit the target aspect ratio."""
    h, w = img.shape[:2]
    scale = min(target_height / h, target_width / w)
    h, w = math.ceil(h * scale), math.ceil(w * scale)
    return cv2.resize(img, (w, h))

file_path = "test.txt"

rle_frames, rows, cols = read_rle_file(file_path)

# Desired FPS
fps = 60
frame_delay = 1 / fps  # Time delay between frames in seconds

for frame_idx, frame in enumerate(rle_frames):
    decompressed_frame = np.zeros((rows, cols, 3), dtype=np.uint8)

    for col_idx, column_channels in enumerate(frame):
        # Decompress each color channel and merge them into the frame
        r_channel = decompress_rle_columns_with_colors(column_channels[0], rows)
        g_channel = decompress_rle_columns_with_colors(column_channels[1], rows)
        b_channel = decompress_rle_columns_with_colors(column_channels[2], rows)
        
        # Combine R, G, B channels into the respective column
        decompressed_frame[:, col_idx, 0] = r_channel
        decompressed_frame[:, col_idx, 1] = g_channel
        decompressed_frame[:, col_idx, 2] = b_channel

    decompressed_frame = resize_image_to_fit(decompressed_frame, 160, 100)
    cv2.imshow(f"vid", decompressed_frame)

    # Regulate frame rate by adding a delay
    if cv2.waitKey(1) & 0xFF == ord('q'):  # Convert delay to milliseconds
        break

    # Ensure a stable 30 FPS by adjusting time
    time.sleep(frame_delay)

cv2.destroyAllWindows()
