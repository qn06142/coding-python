import os
from PIL import Image

def get_smallest_size(directory):
    sizes = []
    for filename in os.listdir(directory):
        if filename.endswith(".jpeg"):
            img = Image.open(os.path.join(directory, filename))
            sizes.append(img.size)
    return min(sizes)

def resize_images(directory, size):
    for filename in os.listdir(directory):
        if filename.endswith(".jpeg"):
            img = Image.open(os.path.join(directory, filename))
            resized_img = img.resize(size)
            resized_img.save(os.path.join(directory, filename))

def main():
    directory = '/run/media/wheatley/NewVolume/coding python/vmvsos/images/'  # replace with your directory
    smallest_size = get_smallest_size(directory)
    resize_images(directory, smallest_size)

if __name__ == "__main__":
    main()
