import serial, sys

ser = serial.Serial()
ser.baudrate = 9600
ser.port = '/dev/cu.wchusbserial51850172361'
ser.open()
print("Current port: " + ser.port)

message = sys.argv[1].encode()
print("Writing command: " + message.decode())
ser.write(message)




total = 0

# while total < len(values):
#     print ord(ser.read(1))
#     total=total+1

ser.close()
