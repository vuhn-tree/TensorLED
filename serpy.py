import serial
import sys, argparse

ser = serial.Serial()
ser.baudrate = 9600
ser.port = '/dev/cu.wchusbserial51850172361'
#ser.port = '/dev/cu.wchusbserial51851974134'
ser.open()
print("Current port: " + ser.port)

parser = argparse.ArgumentParser()
parser.add_argument(dest='color',)

args = parser.parse_args()

print("Writing Message: " + args.color)
ser.write(args.color.encode())

ser.close()
