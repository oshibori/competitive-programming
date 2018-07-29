
def S(n):
    ret=0
    while n>0 :
        ret+=n%10
        n//=10;

    return ret;


#x = [(i*10+9)/S(i*10+9) for i in range(1,200)];
x = [(i)/S(i) for i in range(1,10210)];

import matplotlib.pyplot as plt;

plt.plot(x);
plt.show();
