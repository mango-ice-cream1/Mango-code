
clear all
t=[1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16];
y=[4 6.4 8 8.8 9.22 9.5 9.7 9.86...
   10 10.2 10.32 10.42 10.5 10.55 10.58 10.6 ];

T1=1./t;
Y1=log(y);
m1=polyfit(T1,Y1,1);
b1=m1(1);
A1=m1(2);
a1=exp(A1);
y1=a1*exp(b1./t);%指数拟合浓度
M1=abs(y1-y)./y;%指数拟合的相对误差
Max1=max(M1);%指数拟合的最大相对误差
Ave1=mean(M1);%指数拟合的平均相对误差

T2=1./t;
Y2=1./y;
m2=polyfit(T2,Y2,1);
b2=m2(1);
a2=m2(2);
y2=t./(a2*t+b2);%双曲拟合浓度
M2=abs(y2-y)./y;%双曲拟合的相对误差
Max2=max(M2);%双曲拟合的最大相对误差
Ave2=mean(M2);%双曲拟合的平均相对误差


%图形绘制
hold on
h=scatter(t,y,15,'red','filled');
plot(t,y1,'b-');
plot(t,y2,'k--');
hold off
grid;
xlabel('反应时间');
ylabel('反应物浓度');
title('反应物浓度与时间的关系');
legend('散点图','指数拟合曲线','双曲拟合曲线');
