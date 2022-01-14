#!/usr/bin/env python3

import time
import serial
ser = serial.Serial(port='/dev/ttyUSB0', baudrate=300, bytesize=8, parity='N', stopbits=1, timeout=0, xonxoff=True, 
        rtscts=False, write_timeout=0, dsrdtr=False);
#ser = serial.Serial(
#    port='/dev/ttyUSB0',
#    baudrate=300,
#    parity=serial.PARITY_,
#    #stopbits=serial.STOPBITS_TWO,
#    #bytesize=serial.SEVENBITS
#)
#ser.timeout = 1            #non-block read
##ser.timeout = 0              #timeout block read
#ser.xonxoff = False     #disable software flow control
#ser.rtscts = False     #disable hardware (RTS/CTS) flow control
#ser.dsrdtr = False       #disable hardware (DSR/DTR) flow control
#ser.writeTimeout = 1     #timeout for write
ser.flushInput() #flush input buffer, discarding all its contents
ser.flushOutput()#flush output buffer, aborting current output 

ser.isOpen()
while(True):
    ser.write(str.encode("U")); # 0x55
    print((ser.read(1)))
    #for i in range(0x20, 0x7f):
    #    #ser.write(chr(i).encode())
    #    #ser.write(i.to_bytes(1, "big"))
    #    ser.write(str.encode("HELLO"))
    #    while ser.inWaiting() > 9:
    #        print((ser.read(10)), end="")
    time.sleep(0.1)
#

