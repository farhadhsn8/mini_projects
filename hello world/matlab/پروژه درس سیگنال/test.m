t=-10:0.01:10;
y= sin(t);
subplot(2,2,1);
stem(t,xr(y),'b');
subplot(2,2,2);
stem(t,xo(y),'r');
subplot(2,2,3);
stem(t,xe(y),'g');
subplot(2,2,4);
stem(t,xl(y),'y');
