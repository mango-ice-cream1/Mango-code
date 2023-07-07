clear all

% 作业1
f=[10 5 6 4 8 15]';
A=[-1 -1 -1 0 0 0;
    0 0 0 -1 -1 -1];
b=[-60;-100];
Aeq=[1 0 0 1 0 0;
     0 1 1 1 1 0;
     0 0 1 0 0 1];
beq=[45;75;40];
lb=[0 0 0 0 0 0]';
ub=[];
[x,fval]=linprog(f,A,b,Aeq,beq,lb,ub)

%作业2
f=[3 5 1 0 0 2 ...
   6 4 3 2 5 4 ...
   1 4 2 2 1 2 ...
   1 2 3 3 3 1 ...
   2 1 3 2 4 2 ...
   3 2 5 4 6 6]';
f=-f;
intcon=1:36;
A=[];
b=[];
Aeq=zeros(12,36);
Aeq(1,1:6)=1;
Aeq(2,7:12)=1;
Aeq(3,13:18)=1;
Aeq(4,19:24)=1;
Aeq(5,25:30)=1;
Aeq(6,31:36)=1;
Aeq(7,1:6:31)=1;
Aeq(8,2:6:32)=1;
Aeq(9,3:6:33)=1;
Aeq(10,4:6:34)=1;
Aeq(11,5:6:35)=1;
Aeq(12,6:6:36)=1;
beq=ones(12,1);
lb=zeros(36,1);
ub=ones(36,1);
[x,fval]=intlinprog(f,intcon,A,b,Aeq,beq,lb,ub);
final=reshape(x,6,6)';
final,fval

