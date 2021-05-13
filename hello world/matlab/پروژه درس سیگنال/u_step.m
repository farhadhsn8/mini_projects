function [out1]=u_step(t0)
t=-10:0.01:10;
out1= 1 .* (t>=t0) + 0 .* (t<t0);
end
