function [out1]=ramp2(t0)
t=-10:0.01:10;
out1= (t-t0) .* (t>=t0 & t<t0+1) + 0 .* (t<=t0 & t>t0+1);
end
