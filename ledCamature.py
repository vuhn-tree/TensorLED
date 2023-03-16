#import os, cv2, glob
import cv2
 
# Path to image in local directory
path = '/Users/vuhn/Desktop/test.png'
 
# Using cv2.imread() to read an image in grayscale mode
image = cv2.imread(path, 0)
 
# Using namedWindow()
# A window with 'Display_Image' name is created
# with WINDOW_NORMAL allowing us to have random size
cv2.namedWindow("Display_Image", cv2.WINDOW_NORMAL)
 
# Using cv2.imshow() to display the image
cv2.imshow('Display_Image', image)
 
# Waiting 0ms for user to press any key
cv2.waitKey(1000)
 
# Using cv2.destroyAllWindows() to destroy
# all created windows open on screen
cv2.destroyAllWindows()

# DATA_DIR = os.path.join(os.getcwd(), 'data')
# MODELS_DIR = os.path.join(DATA_DIR, 'models')
# for dir in [DATA_DIR, MODELS_DIR]:
#     if not os.path.exists(dir):
#         os.mkdir(dir)

# import tarfile
# import urllib.request

# # Download and extract model
# MODEL_DATE = '20200711'
# MODEL_NAME = 'ssd_resnet101_v1_fpn_640x640_coco17_tpu-8'

# for camera in glob.glob("/dev/video?"):
#     cap = cv2.VideoCapture(camera)
#     if not cap.isOpened():
#         raise IOError("Cannot open webcam")

#     while True:
#         ret, frame = cap.read()
#         frame = cv2.resize(frame, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_AREA)
#         cv2.imshow('Input', frame)

#         c = cv2.waitKey(1)
#         if c == 27:
#             break

#     cap.release()

# cap = cv2.VideoCapture(camera)
# cv2.startWindowThread()
# cv2.namedWindow('displaymywindows', cv2.WINDOW_AUTOSIZE)

# cap = cv2.VideoCapture(2)

# #Check if the webcam is opened correctly
# if not cap.isOpened():
#     raise IOError("Cannot open webcam")

# while True:
#     ret, frame = cap.read()
#     frame = cv2.resize(frame, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_AREA)
#     cv2.imshow('Input', frame)

#     c = cv2.waitKey(1)
#     if c == 27:
#         break

# cap.release()
# cv2.destroyAllWindows()