import tensorflow as tf
from tensorflow.keras.models import model_from_json
import base64
import json
import numpy as np

# Define the base64 encoded model structure and weights
model_structure_base64 = "PASTE_MODEL_STRUCTURE_BASE64_HERE"
model_weights_base64 = "PASTE_MODEL_WEIGHTS_BASE64_HERE"

# Decode the base64 encoded model structure
model_json = base64.b64decode(model_structure_base64).decode()

# Load the model from JSON
model = model_from_json(model_json)

# Decode the base64 encoded weights
weights_json = base64.b64decode(model_weights_base64).decode()
weights = json.loads(weights_json)
weights = [np.array(w) for w in weights]

# Set the model weights
model.set_weights(weights)

# Compile the model (necessary before using it)
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# Example usage: Predicting a digit from an image
import numpy as np
from PIL import Image

def preprocess_image(image_path):
    img = Image.open(image_path).convert('L')
    img = img.resize((28, 28))
    img_array = np.array(img).astype('float32') / 255
    img_array = img_array.reshape((1, 28, 28, 1))
    return img_array

# Path to the image file
image_path = 'path_to_image.png'
processed_image = preprocess_image(image_path)
prediction = model.predict(processed_image)
predicted_digit = np.argmax(prediction)
print(f'Predicted digit: {predicted_digit}')