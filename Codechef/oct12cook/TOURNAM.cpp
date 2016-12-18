/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int pow_2(int n)
{
    int ans=0;
    while(n)
    {
        ans++;
        n>>=1;
    }
    return ans-1;
}
int pow_8(int n)
{
//    cout<<n<<endl;
    int ans = 0;
    while(n)
    {
        ans++;
        n>>=3;
    }
    return ans-1;
}
int N,M, pow_n;
double P;
int Ms[10000];
set<int> m_set;
int culM[32];
double dp[4][256];
int cnt=0;
map<int,int> foo;
double getans(int from, int size)
{
    if(size==0)
    {
        if(m_set.find(from)!=m_set.end())return 1;
        return 0;
    }
    if(size==3)
    {
        if(foo.find(from)!=foo.end())return dp[3][foo[from]];
    }
    double left = getans(from, size-1), right = getans(from + (1<<(size-1)), size-1);
//    cout<<left<<" "<<right<<endl;
    return left*right + P*(left*(1-right)+(1-left)*right);
}
int main()
{
    in_T
    {
        int tmp;
        foo.clear();
        m_set.clear();
        scanf("%d%d%d", &N,&M,&tmp);
        P=tmp/(double)100;
        pow_n = pow_2(N);
        for(int i=0;i<M;i++)
            {in_I(Ms[i]);m_set.insert(Ms[i]);}
        sort(Ms,Ms+M);
        int q = 0;
        if(pow_n>2)
        while(q<M)
        {
            int cur = (Ms[q]-1)/8;
            int zzz = (Ms[q]-1)/8 +1;
//            cout<<zzz<<endl;
            int tmp = 1<<((Ms[q]-1)%8);
            q++;
            while(q<M && cur == (Ms[q]-1)/8)
            {
                tmp |= 1<<((Ms[q]-1)%8);
                q++;
            }
            foo[zzz]=tmp;
        }
        dp[0][0] = 0;
        dp[0][1] = 1;
        if(pow_n>2)
        for(int i=1;i<4;i++)
        {
            int lt = 1<<i;
            for(int j=0;j<lt;j++)
            {
                for(int k=0;k<lt;k++)
                {
//                    cout<<dp[i-1][j]<<" "<<dp[i-1][k]<<endl;
                    dp[i][(j<<(lt/2))|k] = dp[i-1][j]*dp[i-1][k] + P*(dp[i-1][j]*(1-dp[i-1][k])+dp[i-1][k]*(1-dp[i-1][j]));
//                    cout<<i<<"-"<<((j<<(lt/2))|k)<<" "<<dp[i][(j<<(lt/2))|k]<<endl;
                }
            }
        }
        printf("%.12lf\n",100*getans(1,pow_n));
    }
}
