clear;
clc;

figure;
s=[];
B=5000;
N=87654;
for b=2:B;
  c=floor(log(N)/log(b))
  b
  x=[(b-1) N];
  s=[s min(x)*(c+1)];
end

plot(s);
