function [out1]=xe(x)
n=-10:0.01:10;
y1= x .* (n>-10 & n<10);
y2=fliplr(y1);
out1= (y1 + y2)/2;
end