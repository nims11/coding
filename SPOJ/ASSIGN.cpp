//GQ
/*
    Nimesh Ghelani (nims11)
    DP + bitmask
*/
#include<cstdio>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)

int person_bits[22],n,tmp;long long ans;long long dp[1<<20];
int jobs;int pos;
long long getans()
{
    if(pos==n){return 1;}
    if(dp[jobs]!=-1)return dp[jobs];

    long long &ret=dp[jobs];
    ret=0;
    for(int i=0;i<n;i++)
    {
        if(!(jobs&(1<<i)))
        {
            if(person_bits[pos]&(1<<i))
            {
                jobs|=1<<i;
                pos++;
                ret+=getans();pos--;
                jobs&=~(1<<i);
            }
        }
    }
    return ret;
}
int main()
{
    in_T
    {
        ans=0;
        jobs=0;
        in_I(n);
        for(int i=0;i<n;i++)
        person_bits[i]=0;
        for(int i=0;i<1<<20;i++)
        dp[i]=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                in_I(tmp);
                person_bits[i]|=tmp<<j;
            }
        }pos=0;
        printf("%lld\n",getans());
    }
}


