import serial
import tkinter as tk
import time
import threading
ser = serial.Serial('COM7', 9600, timeout=1)
#serout = serial.Serial('COM8', 9600, timeout=1)



#Aqui se realiza la comunicacion con el Arduino, todas las operaciones
#sobre el arduino se realizan en esta funcion.
def comm():
    while 1:
     try:
      value = ser.readline().decode("utf-8")
      time.sleep(800)
     except ser.SerialTimeoutException:
      print('Data could not be read')
      time.sleep(1)
  


#Aqui se definen los elementos de la interfaz (labels) y tambien su
#configuracion
def Draw():
    global text1,text2,text3,text4,text5,text6,text7,text8

    frame1=tk.Frame(root,width=200,height=200,relief='solid',bd=1)
    frame1.place(x=10,y=50)
    text1=tk.Label(frame1,text='Waiting for conection')
    text1.pack()

    frame2=tk.Frame(root,width=200,height=200,relief='solid',bd=1)
    frame2.place(x=10,y=100)
    text2=tk.Label(frame2,text='Waiting for conection')
    text2.pack()

    frame3=tk.Frame(root,width=200,height=200,relief='solid',bd=1)
    frame3.place(x=10,y=150)
    text3=tk.Label(frame3,text='Waiting for conection')
    text3.pack()

    frame4=tk.Frame(root,width=200,height=200,relief='solid',bd=1)
    frame4.place(x=10,y=200)
    text4=tk.Label(frame4,text='Waiting for conection')
    text4.pack()

    frame5=tk.Frame(root,width=200,height=200,relief='solid',bd=1)
    frame5.place(x=10,y=250)
    text5=tk.Label(frame5,text='Waiting for conection')
    text5.pack()

    frame6=tk.Frame(root,width=200,height=200,relief='solid',bd=1)
    frame6.place(x=10,y=300)
    text6=tk.Label(frame6,text='Waiting for conection')
    text6.pack()

    frame7=tk.Frame(root,width=200,height=200,relief='solid',bd=1)
    frame7.place(x=10,y=350)
    text7=tk.Label(frame7,text='Waiting for conection')
    text7.pack()
    
    frame8=tk.Frame(root,width=200,height=200,relief='solid',bd=1)
    frame8.place(x=180,y=100)
    text8=tk.Label(frame8,text='Waiting for conection')
    text8.pack()
    
#Aqui se refresca la informacion de los labels
def Refresher():
    global text1,text2,text3,text4,text5,text6,text7,text8
    
    tmp = ser.readline().decode("utf-8")
    a = list(tmp.split("@"))
    #print(a)
    if (len(tmp) == 0):
        print("inicio")
    else:
        b = "";
        if (float(a[0]) <= 24):
            b = b + "Low Temperature!!\n"
        
        if (float(a[0]) >= 28):
            b = b + "High Temperature!!\n"
        
        if (float(a[3]) >= 80):
            b = b + "High Humidity!!\n"
        
        if (float(a[5]) == 90):
            b = b + "MidDay!!\n"
        
        if (float(a[5]) == 30 and (a[6] == "E" or a[6] == "SE" or a[6] == "NE")):
            b = b + "Morning!!\n"
        
        if (float(a[5]) == 30 and (a[6] == "O" or a[6] == "SO" or a[6] == "NO")):
            b = b + "Afternoon!!\n"
        
        text1.configure(text = "Temperature: " + a[0] + " C")
        text2.configure(text = "Preassure: " + a[1] + " Pa")
        text3.configure(text = "Altitude: " + a[2] + " m")
        text4.configure(text = "Humidity: " + a[3] + " %")
        text5.configure(text = "Luminosity: " + a[4] + " %")
        text6.configure(text = "Angle: " + a[5] + " degrees")
        text7.configure(text = "Direction: " + a[6] )
        text8.configure(text = b )
        root.after(500, Refresher) 

root=tk.Tk()
root.geometry("350x400") 
Draw()
Refresher()
root.mainloop()
