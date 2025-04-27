import socket
import cv2
import numpy as np
import math
import time
from vidgear.gears import CamGear

# ─── Constants ────────────────────────────────────────────────────────────────
HOST = '127.0.0.1'
PORT = 8000
TARGET_WIDTH, TARGET_HEIGHT = 160, 100
COLOR_REDUCTION = 16
DIFF_THRESHOLD = 20

# ─── Utilities ────────────────────────────────────────────────────────────────
def setup_server(host, port):
    """Sets up the TCP server socket."""
    while True:
        try:
            server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            server.bind((host, port))
            server.listen(5)
            print(f"Listening on {host}:{port}")
            return server
        except OSError:
            print("Port unavailable, retrying...")
            time.sleep(1)

def clear_line(n=1):
    """Clears the last n lines in the console."""
    LINE_UP = '\033[1A'
    LINE_CLEAR = '\x1b[2K'
    print((LINE_UP + LINE_CLEAR) * n, end='')

def resize_image_to_fit(img, target_w, target_h):
    """Resizes the image to fit within a target resolution."""
    h, w = img.shape[:2]
    scale = min(target_h / h, target_w / w)
    new_size = (math.ceil(w * scale), math.ceil(h * scale))
    return cv2.resize(img, new_size)

def colorcrush(r, g, b, reduction):
    """Reduces color depth by a given factor."""
    return tuple((v // reduction) * reduction for v in (r, g, b))

def rgb_to_hex(r, g, b):
    """Converts RGB to integer hex format."""
    r, g, b = colorcrush(r, g, b, COLOR_REDUCTION)
    return r + (g << 8) + (b << 16)

def get_diff_pixels(ref, current, threshold=DIFF_THRESHOLD):
    """Finds pixels that changed beyond a threshold."""
    diff_mask = np.abs(ref.astype(np.int16) - current.astype(np.int16)) >= threshold
    mask = np.any(diff_mask, axis=-1)
    indices = np.argwhere(mask)
    values = current[mask]
    ref[mask] = values
    return indices, values, ref

# ─── Drawing Commands ─────────────────────────────────────────────────────────
def draw(x, y, col, buff):
    return buff + f"DRAW {x} {y} {col} "

def flush_buffer(sock, buff):
    sock.sendall(buff.encode())
    sock.sendall(b"FLSH")
    return ""

def wait_flush_ack(sock):
    return sock.recv(4).decode() == "DONE"

# ─── Main Program ─────────────────────────────────────────────────────────────
if __name__ == "__main__":
    server_socket = setup_server(HOST, PORT)
    conn, addr = server_socket.accept()

    print(f"Connected by {addr}")

    # Setup video stream
    options = {"STREAM_RESOLUTION": "best"}
    path = "https://www.youtube.com/watch?v=PshZOi3VsJU"
    stream = CamGear(source=path, stream_mode="http" in path,
                     backend=cv2.CAP_GSTREAMER, logging=True, **options).start()

    # First frame and reference buffer
    frame = stream.read()
    if frame is None:
        print("Failed to read initial frame.")
        exit(1)

    frame_resized = resize_image_to_fit(frame, TARGET_WIDTH, TARGET_HEIGHT)
    TARGET_WIDTH, TARGET_HEIGHT = frame_resized.shape[1], frame_resized.shape[0]
    ref = np.zeros_like(frame_resized)

    conn.sendall(f"RESO {TARGET_WIDTH} {TARGET_HEIGHT // 2}".encode())

    buffer = ""

    # Main loop
    while True:
        start_time = time.time()
        frame = stream.read()
        if frame is None:
            break

        frame_resized = resize_image_to_fit(frame, TARGET_WIDTH, TARGET_HEIGHT)
        diff_indices, diff_values, ref = get_diff_pixels(ref, frame_resized)

        for (y, x), rgb in zip(diff_indices, diff_values):
            color_int = rgb_to_hex(*rgb)
            buffer = draw(x, y, color_int, buffer)

        buffer = flush_buffer(conn, buffer)
        wait_flush_ack(conn)

        # Frame timing
        elapsed = time.time() - start_time
        target_frame = 1.0 / stream.framerate
        time.sleep(max(0, target_frame - elapsed))

        fps = 1.0 / (time.time() - start_time)
        err = fps - stream.framerate

        clear_line(1)
        print(f"Actual FPS: {fps:.2f}, Error Rate: {err:.2f}")

    # Cleanup
    conn.sendall(b"END")
    conn.recv(3)
    stream.stop()
    server_socket.close()
    print("Server closed.")
