/*
    Nimesh Ghelani (nims11)
    Standard SMP
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
int W[501][501], M[501][501], M_T[501], W_T[501], pref[501], pref_W[501];
int main()
{
    in_T
    {
        int n, tmp, tmp2;
        in_I(n);
        for(int i=1;i<=n;i++)
        {
            in_I(tmp);
            for(int j=1;j<=n;j++)
            {
                in_I(tmp2);
                W[tmp][tmp2] = j;
            }
        }
        for(int i=1;i<=n;i++)
        {
            in_I(tmp);
            for(int j=1;j<=n;j++)
                in_I(M[tmp][j]);
        }
        int count = 0;
        for(int i=0;i<=n;i++)
            M_T[i] = W_T[i] = -1, pref[i] = 1, pref_W[i] = 100000;
        while(count!=n)
        {
            for(int i=1;i<=n;i++)
            {
                if(M_T[i]==-1)
                {
                    int women = M[i][pref[i]];
                    if(pref_W[women]>W[women][i])
                    {
                        if(W_T[women]==-1)
                        {
                            count++;
                        }else
                        {
                            M_T[W_T[women]] = -1;
                        }
                        W_T[women] = i;
                        M_T[i] = women;
                        pref_W[women] = W[women][i];
                    }
                    pref[i]++;
                }
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d %d\n",i, M_T[i]);
    }
}
