import serial
import tkinter as tk
import time
import threading
ser = serial.Serial('COM7', 9600, timeout=1)



#Aqui se realiza la comunicacion con el Arduino, todas las operaciones
#sobre el arduino se realizan en esta funcion.
def comm():
    while 1:
     try:
      value = ser.readline().decode("utf-8")
      time.sleep(200)
      ser.writeline('1')
      time.sleep(200)
     except ser.SerialTimeoutException:
      print('Data could not be read')
      time.sleep(1)
  


#Aqui se definen los elementos de la interfaz (labels) y tambien su
#configuracion
def Draw():
    global text

    frame=tk.Frame(root,width=100,height=100,relief='solid',bd=1)
    frame.place(x=10,y=10)
    text=tk.Label(frame,text='HELLO')
    text.pack()

#Aqui se refresca la informacion de los labels
def Refresher():
    global text
    text.configure(text=ser.readline().decode("utf-8"))
    root.after(200, Refresher) 

root=tk.Tk()
Draw()
Refresher()
root.mainloop()
