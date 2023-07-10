load Data1.mat
y=Data1(:,1);
x1=Data1(:,2);
x2=Data1(:,3);
x3=Data1(:,4);
x4=Data1(:,5);
x5=Data1(:,6);
t=ones(10,1);
X=[t,x1,x2,x3,x4,x5];
[b,bint,r,rint,stats]=regress(y,X)
format long
