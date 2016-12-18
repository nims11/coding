/*
Simple Simulation
*/
#include<cstdio>
#define in_I(a) scanf("%d",&a)
int ans[3001];
const int N=40000;
int sim[N]={0};
int main()
{
    int curr=2;
    for(int i=1;i<=3000;i++)
    {
        ans[i]=curr;
        sim[curr]=1;
        for(int j=curr+1,k=0;j<N;j++)
        {
            if(!sim[j])k++;
            if(k==curr)
            {sim[j]=1;k=0;}
        }
        for(;sim[curr];curr++);
    }
    int n;
    while(1)
    {
        in_I(n);
        if(n==0)break;
        printf("%d\n",ans[n]);
    }
}
