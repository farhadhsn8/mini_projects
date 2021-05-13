t=-10:0.01:10;
x= -ramp2(-2) .* (t>=-2 & t<-1) +2*ramp2(-1)-1 .*(t>=-1 & t<0) + u_step(0) .*(t>=0 & t<2);
y1= -2 * ramp2(-2) .* (t>-2 & t<=-1.5) +((4*ramp2(-1.5))-1) .* (t>-1.5 & t<=-1) + 1 .*(t>=-1 & t<0);
y2= u_step(-1) .* (t>=-1 & t<1) + -2*ramp2(1)+1 .*(t>=1 & t<2) + ramp2(2)-1 .*(t>=2 & t<3);
energy_x =energy(x)/100;
disp(energy_x);
energy_y1 =energy(y1)/100;
disp(energy_y1);
energy_y2=energy(y2)/100;
disp(energy_y2);

