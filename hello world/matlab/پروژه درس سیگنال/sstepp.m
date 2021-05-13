function [] = sstepp(x)
t1=-10:0.01:10;
plot(t1+x,heaviside(t1),'g');
end