import os, cv2

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

cap = cv2.VideoCapture(0)

# Check if the webcam is opened correctly
if not cap.isOpened():
    raise IOError("Cannot open webcam")