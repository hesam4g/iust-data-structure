import random
myfile = open("in.txt","w")
for i in range(10):
    for j in range(12):
        myfile.write(str(random.randint(0,100000)))
        myfile.write(" ")
    myfile.write("\n")

myfile.close()
