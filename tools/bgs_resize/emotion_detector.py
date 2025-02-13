from collections import Counter

import cv2
import numpy as np

def create_background(base_image_path, emotion_image_paths):
    # Load the base image
    base_image = cv2.imread(base_image_path, cv2.IMREAD_UNCHANGED)

    # Initialize a "minimum difference" mask using the first image
    common_mask = np.ones(base_image.shape[:2], dtype=bool)

    # Load all emotion images
    emotion_images = [cv2.imread(path, cv2.IMREAD_UNCHANGED) for path in emotion_image_paths]

    # Iterate over all emotion images to compute the common mask
    for emotion_image in emotion_images:
        diff = cv2.absdiff(base_image, emotion_image)
        threshold = 25  # Adjust for minor variations
        common_mask &= np.all(diff < threshold, axis=-1)

    # Invert the mask to find the "transparent" areas
    transparent_mask = ~common_mask

    # Find connected components (regions) in the transparent mask
    num_labels, labels = cv2.connectedComponents(transparent_mask.astype(np.uint8))

    # Prepare the output background image
    background = base_image.copy()

    # Process each connected region
    for label in range(1, num_labels):  # Start from 1 (0 is the background)
        region_mask = (labels == label)

        # Collect all pixel values for this region from all emotion images
        region_pixels = []
        for emotion_image in emotion_images:
            region_pixels.extend(emotion_image[region_mask])

        # Get the base image's colors in this region
        current_colors = [tuple(color[:3]) for color in base_image[region_mask]]

        # Exclude the current color from the candidates
        filtered_pixels = [tuple(pixel[:3]) for pixel in region_pixels if tuple(pixel[:3]) not in current_colors]

        # Determine the most common replacement color
        if filtered_pixels:
            most_common_color = Counter(filtered_pixels).most_common(1)[0][0]
        else:
            most_common_color = current_colors[0]  # Fallback if no alternatives exist

        # Apply the most common color to the entire region
        for y, x in zip(*np.where(region_mask)):
            background[y, x, :3] = most_common_color

    return background


# Define paths to images
base_image_path = "/Users/n.laptev/development/ksre/game/sprites/emi/emi_basic_annoyed.png"
emotion_image_paths = [
    "/Users/n.laptev/development/ksre/game/sprites/emi/emi_basic_closedgrin.png",
    "/Users/n.laptev/development/ksre/game/sprites/emi/emi_basic_closedhappy.png",
    "/Users/n.laptev/development/ksre/game/sprites/emi/emi_basic_closedsweat.png",
    "/Users/n.laptev/development/ksre/game/sprites/emi/emi_basic_concentrate.png",
]

# Create and save the background image
background = create_background(base_image_path, emotion_image_paths)
cv2.imwrite("background_image.png", background)