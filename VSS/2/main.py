import cv2
import numpy as np
from keras.models import load_model

model = load_model('mnist_cnn_model.h5')


def draw_rectangle(frame, start_point, end_point):
    color = (0, 0, 255)
    thickness = 2
    return cv2.rectangle(frame, start_point, end_point, color, thickness)


def process(frame, start_point, end_point):
    color = (0, 0, 255)
    thickness = 2
    rect = draw_rectangle(frame, start_point, end_point)
    rect1 = draw_rectangle(frame, [20, 20], [225, 70])
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    h_sensivity = 15
    s_h = 255
    v_h = 255
    s_l = 50
    v_l = 50
    blue_upper = np.array([115 + h_sensivity, s_h, v_h])
    blue_lower = np.array([115 - h_sensivity, s_l, v_l])
    red_lower1 = np.array([0, s_l, v_l])
    red_lower2 = np.array([170, s_l, v_l])
    red_upper1 = np.array([15, s_h, v_h])
    red_upper2 = np.array([180, s_h, v_h])
    green_lower = np.array([42, s_l, v_l])
    green_upper = np.array([72, s_h, v_h])
    mask_frame = hsv_frame[start_point[1]:end_point[1] + 1, start_point[0]:end_point[0] + 1]
    mask_red = cv2.inRange(mask_frame, red_lower1, red_upper1) + cv2.inRange(mask_frame, red_lower2, red_upper2)
    mask_blue = cv2.inRange(mask_frame, blue_lower, blue_upper)
    mask_green = cv2.inRange(mask_frame, green_lower, green_upper)
    red_rate = np.count_nonzero(mask_red) / ((end_point[0] - start_point[0]) * (end_point[1] - start_point[1]))
    green_rate = np.count_nonzero(mask_green) / ((end_point[0] - start_point[0]) * (end_point[1] - start_point[1]))
    blue_rate = np.count_nonzero(mask_blue) / ((end_point[0] - start_point[0]) * (end_point[1] - start_point[1]))

    cropped_frame = frame[start_point[1]:end_point[1], start_point[0]:end_point[0]]
    gray = cv2.cvtColor(cropped_frame, cv2.COLOR_BGR2GRAY)
    resized = cv2.resize(gray, (28, 28), interpolation=cv2.INTER_AREA)
    input_data = np.reshape(resized, (1, 28, 28, 1))
    input_data = input_data.astype('float32') / 255
    prediction = model.predict(input_data)
    predicted_class = np.argmax(prediction)
    cv2.putText(frame, str(predicted_class), (50, 100), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)

    org = end_point
    font = cv2.FONT_HERSHEY_SIMPLEX
    fontScale = 0.7
    text1 = cv2.putText(rect1, str(red_rate * 255) + ' ' + str(green_rate * 255) + ' ' + str(blue_rate * 255), [21, 50],
                        font, 0.8, [blue_rate * 255, green_rate * 255, red_rate * 230], 2, cv2.LINE_AA)
    if red_rate > 0.9:
        text = cv2.putText(rect, ' red ', org, font, fontScale, color, thickness, cv2.LINE_AA)
    elif green_rate > 0.9:
        text = cv2.putText(rect, ' green ', org, font, fontScale, color, thickness, cv2.LINE_AA)
    elif blue_rate > 0.9:
        text = cv2.putText(rect, ' blue ', org, font, fontScale, color, thickness, cv2.LINE_AA)
    else:
        text = cv2.putText(rect, ' rainbow ', org, font, fontScale, color, thickness, cv2.LINE_AA)
    return rect, resized


def mouse_callback(event, x, y, flags, param):
    global start_point, end_point, dragging, resizing

    if event == cv2.EVENT_LBUTTONDOWN:
        dragging = True
        start_point = (x, y)
        end_point = (x + 1, y + 1)
        # end_point = (start_point[0]+100, start_point[1]+100)

    elif event == cv2.EVENT_MOUSEMOVE:
        if dragging:
            # end_point = (start_point[0] + 100, start_point[1] + 100)
            end_point = (x + 1, y + 1)
    elif event == cv2.EVENT_LBUTTONUP:
        dragging = False
        # end_point = (start_point[0]+100, start_point[1]+100)
        end_point = (x + 1, y + 1)

    if end_point[0] <= start_point[0] + 20:
        end_point = (start_point[0] + 20, end_point[1])
    if end_point[1] <= start_point[1] + 20:
        end_point = (end_point[0], start_point[1]+20)



# Open Default Camera
cap = cv2.VideoCapture(0)
rect_size = 100
cv2.namedWindow('Cam')
# cv2.namedWindow('Resized')
cv2.setMouseCallback('Cam', mouse_callback)
dragging = False
resizing = False

width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
start_point = (int(height / 2 - rect_size / 2), int(width / 2 - rect_size / 2))
end_point = (int(height / 2 + rect_size / 2), int(width / 2 + rect_size / 2))

while cap.isOpened():
    # Take each Frame
    ret, frame = cap.read()

    processed, resized = process(frame, start_point, end_point)

    cv2.imshow('Cam', processed)
    # cv2.imshow('Resized', resized)

    # Move the rectangle based on arrow keys
    k = cv2.waitKey(1) & 0xFFF
    if k == 52:  # ord 4
        # Quit
        print('Good Bye!')
        break
    elif k == 97:  # left arrow key
        start_point = (max(start_point[0] - 5, 0), start_point[1])
        end_point = (max(end_point[0] - 5, rect_size), end_point[1])
    elif k == 119:  # up arrow key
        start_point = (start_point[0], max(start_point[1] - 5, 0))
        end_point = (end_point[0], max(end_point[1] - 5, rect_size))
    elif k == 100:  # right arrow key
        start_point = (min(start_point[0] + 5, height - rect_size), start_point[1])
        end_point = (min(end_point[0] + 5, height), end_point[1])
    elif k == 115:  # down arrow key
        start_point = (start_point[0], min(start_point[1] + 5, width - rect_size))
        end_point = (end_point[0], min(end_point[1] + 5, width))

# Release the camera and close all windows
cap.release()
cv2.destroyAllWindows()
