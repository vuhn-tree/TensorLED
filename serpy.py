import serial
 
ser = serial.Serial()
ser.baudrate = 115200
ser.port = '/dev/cu.wchusbserial51850172361'
ser.open()
 
values = bytearray([4, 9, 62, 144, 56, 30, 147, 3, 
                    210, 89, 111, 78, 184, 151, 17, 129])

# ser.write(values)
ser.write(bytes(b'g'))
 
total = 0
 
# while total < len(values):
#     print ord(ser.read(1))
#     total=total+1
 
ser.close()