#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int *cost=new int[n];
    for(int i=0;i<n;i++)
    cin>>cost[i];
    int start=-1,sum=0,max=0;
    for(int i=0;i<n;i++)
    {
        if(cost[i]>m){start=-1;continue;}
        if(start==-1)
        {
            start=i;sum=0;
        }
        sum+=cost[i];
        while(sum>m)
        sum-=cost[start++];
        if(sum>max)max=sum;
    }
    cout<<max<<endl;

}
