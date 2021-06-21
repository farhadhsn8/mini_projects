
import math


#(execution time , deadline)

processes = {
  "p0" :  (350 , 410),
  "p1" :  (285 , 325),
  "p2" :  (175 , 190),
  "p3" :  (415 , 425),
  "p4" :  (315 , 390),
  "p5" :  (395 , 445),
}

def laxity(process):
  return process[1] - process[0]

def make_laxity(processes):
  laxities = []
  for process in processes:
    laxities.append(laxity(processes[process]))
  return laxities

def least_laxity_algorithm(processes):
  laxities = make_laxity(processes)
  for i in laxities:
    min_process = laxities.index(min(laxities))
    if(laxities[min_process] != math.inf):
      print("run process : p"+str(min_process))
    laxities[min_process] = math.inf


  
least_laxity_algorithm(processes)




