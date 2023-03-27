import serial
import sys, argparse

ser = serial.Serial()
ser.baudrate = 9600
ser.port = '/dev/cu.wchusbserial51850172361'
ser.open()
print("Current port: " + ser.port)

parser = argparse.ArgumentParser()
parser.add_argument("--color", help="b, g, r")
parser.add_argument("--random", action="store_true", help="random color")

args = parser.parse_args()

if args.random:
    print("random")
else:
    print("Writing Message: " + args.color)
    ser.write(args.color.encode())

ser.close()
