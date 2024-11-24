import tensorflow as tf
from tensorflow.keras import datasets, layers, models
import base64
import json

# Load and preprocess the MNIST dataset
(train_images, train_labels), (test_images, test_labels) = datasets.mnist.load_data()
train_images = train_images.reshape((60000, 28, 28, 1)).astype('float32') / 255
test_images = test_images.reshape((10000, 28, 28, 1)).astype('float32') / 255

# Build the CNN model
model = models.Sequential([
    layers.Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)),
    layers.MaxPooling2D((2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.MaxPooling2D((2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.Flatten(),
    layers.Dense(64, activation='relu'),
    layers.Dense(10, activation='softmax')
])

# Compile the model
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# Train the model
model.fit(train_images, train_labels, epochs=1, validation_data=(test_images, test_labels))

# Save the model to a base64 encoded string
model_json = model.to_json()
model_weights = model.get_weights()

# Convert weights to base64
weights_base64 = base64.b64encode(json.dumps([w.tolist() for w in model_weights]).encode()).decode()

# Save model structure and weights as base64 encoded strings
model_structure_base64 = base64.b64encode(model_json.encode()).decode()

# Print the base64 encoded model structure and weights
print("Model Structure Base64:")
#print(model_structure_base64)
print("Model Weights Base64:")
#print(weights_base64)
with open("model.base64", "w") as f:
    f.write(model_structure_base64 + "\n" + model_weights)