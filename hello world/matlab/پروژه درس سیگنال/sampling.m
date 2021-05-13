t1=-10:0.01:10;
t2=-10:0.1:10;
t3=0:0.01:1;
t4=0:0.1:1;
stem(t1,heaviside(t1),'g');
figure;
stem(t2,heaviside(t2),'c');
figure;
stem(t3,t3,'r');
figure;
stem(t4,t4,'p');


