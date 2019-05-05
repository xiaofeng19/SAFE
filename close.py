import time

f=open("./InputData/close.txt",'w')
f.write("close")
f.close()

time.sleep(1)

f=open("./InputData/close.txt",'w')
f.write("")
f.close()