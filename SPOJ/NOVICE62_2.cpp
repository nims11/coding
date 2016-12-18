#include<stdio.h>
#define M 1000000007
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        int sign=n%2?-1:1;
        long long pre=1;
        int ans=sign*pre;
        sign*=-1;
        for(int i=n-1;i>=2;i--,sign*=-1)
        {
            pre*=i+1;pre%=M;
//            cout<<pre<<endl;
            ans+=(pre*sign);if(ans>0)ans%=M;
            printf("%d\n",ans);
        }
        printf("%d\n",ans);
    }
}

