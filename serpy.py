import serial, argparse

ser = serial.Serial()
ser.baudrate = 9600
# ser.port = '/dev/cu.wchusbserial51850172361'
# ser.port = '/dev/cu.usbserial-027A3CF8'
ser.port = '/dev/ttyUSB0'
ser.open()
print("Current port: " + ser.port)

parser = argparse.ArgumentParser()
parser.add_argument("--color", help="b, g, r, n")
parser.add_argument("--servo", help="90 - 90")
parser.add_argument("--random", action="store_true", help="random color")

args = parser.parse_args()

if args.color:
    print("Writing Message: " + args.color)
    ser.write(args.color.encode())

if args.servo:
    print("Servo Angle: " + args.servo)
    msg = "servo" + args.servo
    ser.write(msg.encode())

if args.random:
    print("random")
    while(True):
        ser.write('g'.encode())


ser.close()
