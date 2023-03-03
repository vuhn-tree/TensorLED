import serial, sys

ser = serial.Serial()
ser.baudrate = 115200
ser.port = '/dev/cu.wchusbserial51850172361'
ser.open()
ser.write(sys.argv[1].encode())

total = 0

# while total < len(values):
#     print ord(ser.read(1))
#     total=total+1

ser.close()
