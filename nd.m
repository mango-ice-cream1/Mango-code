clear all
t=[0.25 0.5 1 1.5 2 3 4 6 8];
c=[19.21 18.15 15.36 14.10 12.89 9.32 7.45 5.24 3.01];

X1=t;
Y1=log(c);
m1=polyfit(X1,Y1,1);
b1=-m1(1);
A1=m1(2);
a1=exp(A1);
y1=a1*exp(-b1*t);%指数拟合浓度
M1=abs(y1-c)./c;%指数拟合的相对误差
Max1=max(M1);%指数拟合的最大相对误差
Ave1=mean(M1);%指数拟合的平均相对误差

X2=t;
Y2=1./c;
m2=polyfit(X2,Y2,1);
a2=m2(1);
b2=m2(2);
y2=1./(a2*t+b2);%双曲拟合浓度
M2=abs(y2-c)./c;%双曲拟合的相对误差
Max2=max(M2);%双曲拟合的最大相对误差
Ave2=mean(M2);%双曲拟合的平均相对误差

%图形绘制
hold on
scatter(t,c,15,'red','filled');
grid;
plot(t,y1,'r-');
plot(t,y2,'k--');
hold off
legend('散点图','指数拟合','反比例拟合');
title('血药浓度和时间的关系');
xlabel('时间t(hour)');
ylabel('浓度C(ug/ml)');
