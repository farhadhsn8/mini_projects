import numpy as np
import datetime as dt

def dijestra(res_net,m,source,target,path):
    s=[0]*m
    dist=[9999]*m
    dist[source]=0
    s[source]=1
    v=source
    tmp=0
    tmp1=0
    #print(s[target])
    while(s[target]==0 and tmp!=-2):  #tmp==2 ==> cut
        min = 9999
        tmp=-2
        for i in range(0,m):
            if(res_net[v][i]>0  and dist[i] > (res_net[v][i]+dist[v])):
                path[i]=v
                dist[i]=res_net[v][i]+dist[v]
                #print(path)
        for i in range(0,m):
            for j in range(0,m):
                if (s[i]==1 and s[j]==0 and res_net[i][j]>0 and min>dist[j]):
                    min = dist[j]
                    tmp=j
                    tmp1=i
                    #print(path)
        s[tmp]=1

        #print(tmp)
        v=tmp
        path[tmp]=tmp1

    if (s[target]==1):
        #print('qqqqq')
        return True
    if (s[target]==0):
        #print('finish')
        return False




def fordFulkerson(net,m,source,target):
    res_net=np.zeros((m,m))
    for i in range(m):
        for j in range(m):
            res_net[i][j]=net[i][j]

    max_flow=0#result
    path= np.array([-1]*m)#store path
    while(dijestra(res_net,m,source,target,path)==True):
        flow = 9999999
        l=target
        while(l != source):
            flow=min(flow,res_net[path[l]][l])
            l=path[l]
        #max_flow+=flow

        k=target
        while(k != source):
            l=path[k]
            res_net[l][k]-=flow
            res_net[k][l]+=flow
            k=path[k]
        max_flow+=flow
    return max_flow


time1=dt.datetime.now()   
f = open("salam.txt")
a=f.readline()
a=a.split()
m=int(a[0])
n=int(a[1])
        

net=np.zeros((m,m))
#print(net)
for i in range(0,n):
    a=f.readline()
    a=a.split()
    x=int(a[0])
    y=int(a[1])
    z=int(a[2])
    net[x][y]=z
    #print(x,y,z)
#print(net)   
    
      
print(fordFulkerson(net,m,0,m-1)) 

time2=dt.datetime.now()
time = time2 - time1
print("run time is : ", end='\t' )
print(time)