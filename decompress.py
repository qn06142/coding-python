import numpy as np
import cv2
import math
import time
import cv2.dnn_superres

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
    new_h, new_w = math.ceil(h * scale), math.ceil(w * scale)
    return cv2.resize(img, (new_w, new_h), interpolation=cv2.INTER_LINEAR)

# File containing the RLE encoded data
file_path = "test.txt"

rle_frames, rows, cols = read_rle_file(file_path)

# Initialize the AI upscaler using OpenCV's DNN Super Resolution module.
sr = cv2.dnn_superres.DnnSuperResImpl_create()
model_path = "FSRCNN_x3.pb"
sr.readModel(model_path)

sr.setPreferableTarget(cv2.dnn.DNN_TARGET_CUDA)
# Set the model type and scale (here, using 'edsr' with scale factor 3).
sr.setModel("fsrcnn", 3)
# Desired FPS and frame delay
fps = 30
frame_delay = 1 / fps  # Time delay between frames in seconds

for frame_idx, frame in enumerate(rle_frames):
    # Create an empty image for the current frame
    cur = time.time()
    decompressed_frame = np.zeros((rows, cols, 3), dtype=np.uint8)

    # Decompress each column for R, G, B channels
    for col_idx, column_channels in enumerate(frame):
        r_channel = decompress_rle_columns_with_colors(column_channels[0], rows)
        g_channel = decompress_rle_columns_with_colors(column_channels[1], rows)
        b_channel = decompress_rle_columns_with_colors(column_channels[2], rows)
        
        decompressed_frame[:, col_idx, 0] = r_channel
        decompressed_frame[:, col_idx, 1] = g_channel
        decompressed_frame[:, col_idx, 2] = b_channel

    # Upscale the image using the AI model
    upscaled_frame = sr.upsample(decompressed_frame)

    # Optionally resize the upscaled image to fit the display window
    final_frame = upscaled_frame

    # Display the frame
    cv2.imshow("vid", final_frame)

    # Exit if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    time.sleep(max(0, frame_delay - (time.time() - cur)))

cv2.destroyAllWindows()
