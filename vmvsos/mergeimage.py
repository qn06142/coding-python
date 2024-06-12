import os
import numpy as np
from PIL import Image

def median_images(directory):
    images = []
    sizes = set()
    modes = set()
    for filename in os.listdir(directory):
        if filename.endswith(".jepg") or filename.endswith(".png"):
            img = Image.open(os.path.join(directory, filename)).convert('L')
            images.append(np.array(img))
            sizes.add(img.size)
            modes.add(img.mode)

    if len(sizes) > 1:
        raise ValueError("All images must be the same size.")
    if len(modes) > 1:
        raise ValueError("All images must have the same number of color channels.")

    # Calculate the median
    median_img = np.median(images, axis=0)

    # Convert median image numpy array to PIL Image
    median_img_pil = Image.fromarray(np.uint8(median_img))

    # Convert to black and white
    bw_img = median_img_pil.point(lambda x: 0 if x<128 else 255, '1')

    # Save the median image
    bw_img.save(os.path.join(directory, 'median_image.jpg'))

def main():
    directory = '/run/media/wheatley/NewVolume/coding python/vmvsos/images/'  # replace with your directory
    median_images(directory)

if __name__ == "__main__":
    main()
