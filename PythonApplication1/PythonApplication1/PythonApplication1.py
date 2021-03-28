
import numpy as np
import queue

def bfs(res_net,m,source,target,path):
    visited=[False]*m
    q=queue.Queue(maxsize=9999)
    q.put(source)
    visited[source]=True
    path[source]=-1

    while( q.empty() != True):
        k=q.get()
        for i in range(m):
            if (visited[i]==False and res_net[k][i] > 0):
                q.put(i)
                path[i]=k
                visited[i]=True
    return visited[target]


def fordFulkerson (net,m,source,target):
    res_net=np.zeros((m,m))
    for i in range(m):
        for j in range(m):
            res_net[i][j]=net[i][j]

    max_flow=0#result
    path= np.array([]*m)#store path
    while (bfs(res_net,m,source,target,path)==True):
        flow = 9999999
        l=target
        while(l != source):
            flow=min(flow,res_net[path[l]][l])
            l=path[l]
        max_flow+=flow

        k=target
        while(k != source):
            l=path[k]
            res_net[l][k]-=flow
            res_net[k][l]+=flow
            k=path[k]
        max_flow+=flow
    return max_flow

net =  [[0, 16, 13, 0, 0, 0], 
        [0, 0, 10, 12, 0, 0], 
        [0, 4, 0, 0, 14, 0], 
        [0, 0, 9, 0, 0, 20], 
        [0, 0, 0, 7, 0, 4], 
        [0, 0, 0, 0, 0, 0]] 
   

   
print(fordFulkerson(net,6,0,5)) 
  
