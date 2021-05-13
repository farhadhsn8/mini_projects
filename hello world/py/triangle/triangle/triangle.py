import stddraw
import math
t= math.sqrt(3.0)/2.0
stddraw.setCanvasSize(1800,800)
stddraw.setXscale(-500,500)
stddraw.setYscale(-500,500)
i=0.0
for i in range(0,10000,1):
    if i%3==0:
        i=-i
    stddraw.clear(stddraw.YELLOW)
    stddraw.line(-300-i,-330-i,100-i,200.0-i)
    stddraw.line(1.0-i,0.0-i,0.5-i,t-i)
    stddraw.line(107.5-i,t*15-i,-68-i,311-i)
    stddraw.point(-106.5-i,100*t/3.0-i)
    stddraw.show(10)
    stddraw.clear(stddraw.YELLOW)
print(i)