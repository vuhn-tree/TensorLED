import serial
import sys, argparse

ser = serial.Serial()
ser.baudrate = 9600
#ser.port = '/dev/cu.wchusbserial51850172361'
ser.port = '/dev/cu.wchusbserial51851974134'
ser.open()
print("Current port: " + ser.port)

parser = argparse.ArgumentParser()
parser.add_argument(color='color',)
message = sys.argv[1].encode()

if (message == 'm')


print("Writing command: " + message.decode())
ser.write(message)

ser.close()
