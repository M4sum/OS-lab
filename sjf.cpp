#include<iostream>
using namespace std;

int *b,*flag,*a,totalTime=0,temp,n,*c,countt;

int shortestCompletionTime(){
    int min=1000;
    int min_index=0;
    for(int i=1;i<n;i++){
        if(flag[i]!=1 && b[i]<=min && a[i]<=totalTime)
        {
            min=b[i];
            min_index=i;
        }
    }
    return min_index;
}

void completionTime(){
    cout<<endl<<"completeion times are:"<<endl;
    c[0]=a[0]+b[0];
    totalTime = c[0];
    flag[0]=1;
    while(countt!=n-1){
        for(int i=1;i<n;i++){      
            if(a[i]<totalTime && flag[i]!=1){
                temp=shortestCompletionTime();
                c[temp] = totalTime + b[temp];
                totalTime = c[temp];
                flag[temp]=1;
                countt++;
            }
            else if(flag[i]!=1 && a[i]>=totalTime){
                totalTime =c[i] =a[i]+b[i];
                flag[i]=1;
                countt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i+1<<"."<<c[i]<<endl;
    }
}

int main(){
    cin>>n;
    a=new int[n];
    b=new int[n];
    c=new int[n];
    flag=new int[n];
    cout<<"enter a.t. and b.t. for values for each process"<<endl;
    for(int i=0; i<n; i++) {
        cin>>a[i]>>b[i];
        flag[i]=0;
    }
    completionTime();
    return 0;
}
