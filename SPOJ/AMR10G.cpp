#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k,n;
        scanf("%d%d",&n,&k);
        long long height[20010];
        long long s;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&height[i]);
        }
        sort(height,height+n);
        long long min=1000000001;
        for(int i=0;i<=n-k;i++)
        {
            long long diff=height[i+k-1]-height[i];
            if(diff<min)
            min=diff;
        }
        cout<<min<<endl;
    }
    return 0;
}
