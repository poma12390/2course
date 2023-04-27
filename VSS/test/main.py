import cv2
import numpy as np

def draw_rectangle(frame, start_point, end_point):
    color = (0, 0, 255)
    thickness = 2
    return cv2.rectangle(frame, start_point, end_point, color, thickness)

def process(frame, start_point, end_point):
    rect = draw_rectangle(frame, start_point, end_point)
    return rect

# Mouse callback function
def mouse_callback(event, x, y, flags, param):
    global start_point, end_point, dragging, resizing

    if event == cv2.EVENT_LBUTTONDOWN:
        dragging = True
        start_point = (x, y)
        end_point = (x, y)

    elif event == cv2.EVENT_MOUSEMOVE:
        if dragging:
            end_point = (x, y)

    elif event == cv2.EVENT_LBUTTONUP:
        dragging = False
        end_point = (x, y)

# Open Default Camera
cap = cv2.VideoCapture(0)
cv2.namedWindow('Cam')
cv2.setMouseCallback('Cam', mouse_callback)

dragging = False
resizing = False
start_point = (0, 0)
end_point = (0, 0)

while cap.isOpened():
    # Take each Frame
    ret, frame = cap.read()

    processed = process(frame, start_point, end_point)
    # Show video
    cv2.imshow('Cam', processed)

    # Exit if "4" is pressed
    k = cv2.waitKey(1) & 0xFF
    if k == 52:  # ord 4
        # Quit
        print('Good Bye!')
        break

# Release the camera and close all windows
cap.release()
cv2.destroyAllWindows()
