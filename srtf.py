n = int(input())
arr=[]
bur=[]
flag=[]
comp=[]
time=0
count=0

def minTime():
    minimum=100000
    minIndex=0
    for i in range(n):
        if arr[i]<=time and flag[i]==0 and bur[i]<minimum:
            minimum=bur[i]
            minIndex=i
    return minIndex

for i in range(n):
    a,b=input().split()
    arr.append(int(a))
    bur.append(int(b))
    flag.append(0)
    comp.append(0)
plist = list(zip(arr,bur))
plist.sort()
arr,bur=map(list,zip(*plist))

while(count<n):
    for i in range(n):
        if arr[i]<=time and flag[i]==0:
            index=minTime()
            print(index)
            if bur[index]>0:
                comp[index]=time
                bur[index]-=1
                time+=1
            else:
                flag[index]=1
                count+=1
        elif arr[i]>time and flag[i]==0:
            if bur[i]>0:
                comp[i]=(arr[i]-time)
                time=arr[i]
            else:
                flag[i]=1
                count+=1
print(comp)