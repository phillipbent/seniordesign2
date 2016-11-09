
import bluetooth
 
bd_addr = "00:06:66:52:FC:DB" #the address from the Arduino sensor
port = 1
sock = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
sock.connect((bd_addr,port))
 
 place = 0
 
while place == 0:
	try:

		data = sock.recv(1024)
		if data =="1":
				print data
				sock.send("2")
				place=1
				
	except:
                pass
 
sock.close()
