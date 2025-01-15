from vidgear.gears import CamGear
import cv2
import numpy as np
import math

def resize_image_to_fit(img, target_width, target_height):
    """Resize the image to fit the target aspect ratio."""
    h, w = img.shape[:2]
    scale = min(target_height / h, target_width / w)
    h, w = math.ceil(h * scale), math.ceil(w * scale)
    return cv2.resize(img, (w, h))
def colorReduce(image, div=64):
    nl, nc = image.shape[:2]
    
    # Loop through each row
    for j in range(nl):
        # Loop through each column of the row
        for i in range(nc):
            # Process each pixel
            image[j, i] = (image[j, i] // div) * div + div // 2
    return image
def rle_compress_columns(binary_image):
    """Compress a 2D binary array using RLE column by column."""
    rows, cols = binary_image.shape
    rle_columns = []
    for col in range(cols):
        column = binary_image[:, col]
        rle = []
        prev_value = column[0]
        count = 0
        for value in column:
            if value == prev_value:
                count += 1
            else:
                rle.append((prev_value, count))
                prev_value = value
                count = 1
        rle.append((prev_value, count))
        rle_columns.append(rle)
    return rle_columns

def rle_compress_frame(frame):
    """Compress a 3-channel image using RLE for each channel."""
    channels = cv2.split(frame)
    return [rle_compress_columns(colorReduce(channel)) for channel in channels]

def write_rle_to_file(file, rle_channels):
    """Write RLE-compressed data interleaved as R, G, B on each line to the file."""

    num_rows = len(rle_channels[0])  

    for row_idx in range(num_rows):
        for channel in rle_channels:
            interleaved_row = list(f"{value} {length}" for value, length in channel[row_idx])
            file.write(" ".join(interleaved_row) + "\n")

options = {"STREAM_RESOLUTION": "240p"}
vid = CamGear(source='/home/wheatley/Videos/March 7th.mp4', backend=cv2.CAP_GSTREAMER, logging=True, **options).start()

output_file = "test.txt"
with open(output_file, "w") as f:

    target_width, target_height = 160, 100
    frame = vid.read()

    frame = resize_image_to_fit(frame, target_width, target_height)
    target_width, target_height = frame.shape[1], frame.shape[0]
    f.write(f"{target_height} {target_width}\n")

    while True:
        frame = vid.read()
        if frame is None:
            break

        frame = resize_image_to_fit(frame, target_width, target_height)

        compressed_frame = rle_compress_frame(frame)

        write_rle_to_file(f, compressed_frame)

        resized_frame = resize_image_to_fit(frame, 1024, 576)
        cv2.imshow("Video Stream", resized_frame)

        if cv2.waitKey(25) & 0xFF == ord('q'):
            break

vid.stop()
cv2.destroyAllWindows()