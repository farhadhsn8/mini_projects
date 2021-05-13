import numpy as np
import datetime as dt


def dfs(res_net,m,source,target, path):
    visited=[0]*m
    stack=[]
    stack.append(source)
    v=source
    visited[source]=1
    path[source]=-1
    while(len(stack)!=0):
        flag=0   #hamsayeh nadarad
        for i in range(0,m):
            if(res_net[v][i]!=0 and visited[i]==0):
                path[i]=v
                v=i
                stack.append(i)
                visited[i]=1
                flag=1  #hamsayeh darad
                break
        if(flag==0 and len(stack)>0):    
            stack.pop()
            if(len(stack)>0):
                v=stack[len(stack)-1]
    if(visited[target]):
        return True
    else:
        return False

    




def fordFulkerson(net,m,source,target):
    res_net=np.zeros((m,m))
    for i in range(m):
        for j in range(m):
            res_net[i][j]=net[i][j]

    max_flow=0#result
    path= np.array([-1]*m)#store path
    while(dfs(res_net,m,source,target,path)==True):
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