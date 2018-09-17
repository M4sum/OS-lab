from operator import attrgetter
class process:
    def __init__(self,arr,bur):
        self.arr=arr
        self.bur=bur

n = int(input())
p=[]
for i in range(n):
    a=input().split()
    p.append((process(int(a[0]),int(a[1]))))
print(p[0].arr)