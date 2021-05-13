t=-10:0.01:10;
xt= -ramp2(-2) .* (t>=-2 & t<-1) +2*ramp2(-1)-1 .*(t>=-1 & t<0) + u_step(0) .*(t>=0 & t<2);
v=fliplr(xl(xt));
y1=2*xo(xt)+v;
y2=xl(xt);
y=y1.* (t>0) +y2 .* (t<0);
plot(t,y,'r');