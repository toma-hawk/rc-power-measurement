import serial
import time 
import csv

ser = serial.Serial('COM3',baudrate=9600)

while True:
    try:
        ser_bytes= ser.readline().decode('ascii')
        print(ser_bytes)
        data_split=ser_bytes.split(",")
        with open("battery_charging_test_1.csv","a") as f:
            writer = csv.writer(f,delimiter=",")
            writer.writerow([time.time(),data_split[0],data_split[1][0:len(data_split[1])-2]])
    except:
        print("Keyboard Interrupt")
        break
