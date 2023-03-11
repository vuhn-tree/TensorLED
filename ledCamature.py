import os, cv2, glob

DATA_DIR = os.path.join(os.getcwd(), 'data')
MODELS_DIR = os.path.join(DATA_DIR, 'models')
for dir in [DATA_DIR, MODELS_DIR]:
    if not os.path.exists(dir):
        os.mkdir(dir)

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

cap = cv2.VideoCapture(2)

#Check if the webcam is opened correctly
if not cap.isOpened():
    raise IOError("Cannot open webcam")

while True:
    ret, frame = cap.read()
    frame = cv2.resize(frame, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_AREA)
    cv2.imshow('Input', frame)

    c = cv2.waitKey(1)
    if c == 27:
        break

cap.release()
cv2.destroyAllWindows()