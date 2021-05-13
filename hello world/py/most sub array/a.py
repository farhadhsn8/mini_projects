import sys
import random as rn 
import datetime as dt


def RandL(arr,a1,a2):
     if a1==a2:
         return arr[a1]
     else:
        mid=(a1+a2)//2
        left=RandL(arr,a1,mid)
        right=RandL(arr,mid+1,a2)
        if right>left:
            return right
        else:
            return left


sum_1=0
nn=1000#num of ex
for i in range(0,nn):
    #n=int(input("please enter size of array : "))
    n=1000#size of array
    
    time1=dt.datetime.now()
    arr=[]
    integrate=[]
    sum = 0
    for i in range (0,n):
        x=int(rn.uniform(-1000,1000))
        arr+=[x]
        sum+=x
        integrate+=[sum]
    #for i in range(0,n):
        #print(int(arr[i]))
    #for i in range(0,n):
        #print(int(integrate[i]))
    #print(arr)
    mid=n//2;
    max1 =0
    sum1 = 0
    p1 =0
    p2 =0
    for i in range(mid,-1,-1):
        sum1+=arr[i]
        if sum1>max1:
            max1=sum1
            p1=i
    max2 =0
    sum2 = 0
    for i in range(mid+1,n):
        sum2+=arr[i]
        if sum2>max2:
            max2=sum2
            p2=i

    maxx=RandL(arr,0,n-1)
    if maxx<max1+max2:
        maxx=max1+max2
   # print (maxx)
      
    sum_1+=maxx        
        
print ("avg of lentgh : " , end=" ")
print (sum_1/nn)
print (sum_1)
    
