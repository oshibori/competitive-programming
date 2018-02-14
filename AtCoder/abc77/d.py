K=int(input())
def f(x):
    ret=0
    while x > 0:
        ret+=x%10
        x//=10
    return ret

a=[]
for i in range(10):
    a.append(f((i+1)*K))

print(min(a))
