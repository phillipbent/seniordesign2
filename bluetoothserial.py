import serial
from time import sleep

bluetoothSerial = serial.Serial('/dev/rfcomm1',115200,timeout=1)

send  = 0
place = 0
recieve =0

while place  ==0 :
     try:
          recieve =  bluetoothSerial.readline()
          if recieve =="1":
               print recieve
               bluetoothSerial.write("2")
               place=1
     except:
          pass

bluetoothSerial.close()
