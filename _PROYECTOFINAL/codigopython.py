import serial
import time
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

ser = serial.Serial('COM9', 9600, timeout=3)
time.sleep(2)
y=[]
data = []

for i in range(100):
    y.append(i)
    line = ser.readline()   
    if line:
        string = line.decode()  
        num = int(string) 
        print(num)
        data.append(num) 
ser.close()
counter = 0
for i in data:
     
    newvalue = i*60/13 
    data[counter]=newvalue
    counter +=1



plt.xlabel('Time')
plt.ylabel('DB')
plt.title('AUDIO VS TIMEEEE')
plt.scatter(y,data)





Yvec = np.array(data)
Y = np.reshape(Yvec,(-1,1))


v = np.ones(len(y))


At = np.vstack((v,y))
print(At)

A = np.transpose(At)

B = np.dot(np.linalg.inv(np.dot(At,A)),np.dot(At,Y))

print(f'y=',B[1], 'x','+', B[0])

datax = []
datay = []

for i in range(100):
    datax.append(i)
    yv = i*B[1]+B[0]
    datay.append(yv)
    



plt.plot(datax,datay,'-r')
plt.show()

