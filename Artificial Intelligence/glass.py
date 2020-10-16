a=0             #intial conditions
b=0
x=[a,b]

def empty(ch):
    global a,b,x
    if(ch == 1):
        a = 0
        print("empied 3l vessel ", end='')
    if(ch == 2):
        b = 0
        print("empied 5l vessel ", end='')
    x = [a, b]
    print(x)          # value update

def fill(ch):
    global a,b,x
    if(ch == 1):
        a = 3
        print("filled 3l vessel ",end='')
    if(ch == 2):
        b = 5
        print("filled 5l vessel ", end='')
    x = [a, b]
    print(x)          # value update

def fillv(t, f):
    global a,b,x
    if(t==1 and f==2):
        if(b!=5):
            print("no water in 5l first fill ", end='')
        elif(a==3):
            print("3l vessel is full", end='')
        elif(a==2):
            b=4
            a=3
        elif(a==1):
            b=3
            a=3
        else:
            a=3
            b=2
    if(t==2 and f==1):
        if(a==0):
            print("no water in vessel 1 ", end='')
        elif (a==3):
            if(b==0):
                b=b+a
                a=0
            elif (b==3):
                b=b+2
                a=1
        elif (a==1):
            if(b==0):
                b=1
                a=0
    x=[a,b]
    print("Tranfer of Water status",x)

while(1):
    if(x==[0,4] or  x==[1,3] or x==[2,2] or x==[3,1]):
        print("We have 4l water!! ", end='')
        break
    empty(1)
    empty(2)
    fill(1)
    fillv(2,1)
    empty(1)
    fill(1)
    fillv(2,1)
    empty(2)
    fillv(2,1)
    fill(1)
    fillv(2,1)




