import serial
import sys

ser = serial.Serial()
ser.baudrate = 9600
#ser.port = '/dev/cu.wchusbserial51850172361'
ser.port = '/dev/cu.wchusbserial51851974134'
ser.open()
print("Current port: " + ser.port)

message = sys.argv[1].encode()
print("Writing command: " + message.decode())
ser.write(message)

ser.close()
