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
#include<cstring>
#include<cstdlib>
#include<cassert>
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
char str[12][12];
string hashes[12][12][12][12];
void calc(int i1, int j1, int i2, int j2)
{
    hashes[i1][j1][i2][j2] = "";
    for(int i = i1;i<=i2;i++)
    {
        for(int j = j1;j<=j2;j++)
            hashes[i1][j1][i2][j2].push_back(str[i][j]);
        hashes[i1][j1][i2][j2].push_back('\n');
    }
}
int main()
{
    in_T
    {
        int n,m;
        in_I(n);in_I(m);
        for(int i = 0;i<n;i++)
            in_S(str[i]);
        int ans = 0;
        for(int i = 0; i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                for(int i1 = i;i1<n;i1++)
                {
                    for(int j1 = j;j1<m;j1++)
                    {
                        calc(i, j, i1, j1);
                    }
                }
            }
        }
        int loop = 0;
        for(int i = 0; i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                for(int i1 = i;i1<n;i1++)
                {
                    for(int j1 = j;j1<m;j1++)
                    {
                        for(int i2 = 0;i2<n;i2++)
                        {
                            for(int j2 = 0;j2<m;j2++, loop++)
                                if(!(i2 == i && j2 == j) && i2+i1-i <n && j2+j1-j < m && hashes[i][j][i1][j1] == hashes[i2][j2][i2+i1-i][j2+j1-j])
                                {
                                    ans = max(ans, (i1-i+1)*(j1-j+1));
                                }
                        }
                    }
                }
            }
        }
        cout<<loop<<endl;
        printf("%d\n", ans);
    }
}
