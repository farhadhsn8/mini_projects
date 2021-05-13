import numpy as np
import queue
import datetime as dt

def bfs(res_net,m,source,target,path):
    visited=[False]*m
    q=queue.Queue(maxsize=9999)
    q.put(source)
    visited[source]=True
    path[source]=-1

    while( q.empty() != 1):
        k=q.get()
        for i in range(m):
            if (visited[i]==False and res_net[k][i] > 0):
                q.put(i)
                path[i]=k
                visited[i]=True
    return visited[target]


def fordFulkerson(net,m,source,target):
    res_net=np.zeros((m,m))
    for i in range(m):
        for j in range(m):
            res_net[i][j]=net[i][j]

    max_flow=0#result
    path= np.array([-1]*m)#store path
    while(bfs(res_net,m,source,target,path)==True):
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
  
