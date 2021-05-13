import sys
import random as rn 
import datetime as dt

n=int(input("please enter size of array : "))
time1=dt.datetime.now()
arr=[]
integrate=[]
sum = 0
for i in range (0,n):
    x=int(rn.uniform(-10,10))
    arr+=[x]
    sum+=x
    integrate+=[sum]
#for i in range(0,n):
    #print(int(arr[i]))
#for i in range(0,n):
    #print(int(integrate[i]))
print(arr)
max =0
sum = 0
p1 =0
p2 =0
for i in range(0,n):
    for j in range(i,n):
        if i==0:
            sum= integrate[j]
        else:
            sum=integrate[j]-integrate[i-1]
        if sum>max:
            max=sum
            p1=i
            p2=j
print ("max sub array is : " , end=" ")
print(max)
print ("from : " , end=" ")
print(p1)
print ("to : " , end=" ")
print(p2)
time2=dt.datetime.now()
time = time2 - time1
print("run time is : ", end='\t' )
print(time)






    
