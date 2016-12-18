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
char grid[25][25];
int check(int i1, int j1, int i2, int j2)
{
    int ret = 0;
    for(int i = i1;i<=i2;i++)
        for(int j = j1;j<=j2;j++)
        {
            if(grid[i][j] == '.')
                return -1;
            ret+= (grid[i][j] == '#');
        }
    return ret;
}
int main()
{
    int z = 0;
    in_T
    {
        z++;
        int n;
        in_I(n);
        int tot = 0;
        for(int i = 0;i<n;i++)
        {
            in_S(grid[i]);
            for(int j = 0;grid[i][j];j++)
                tot += (grid[i][j] == '#');
        }
        bool flag = false;
        for(int i1 = 0; i1<n;i1++)
            for(int j1 = 0;j1<n;j1++)
                for(int len = 1;len<=n;len++)
        {
            if(i1+len-1 < n && j1 + len-1 < n && check(i1, j1, i1+len-1, j1+len-1) == tot)
            {
                flag = true;
                j1 = len = n+1;
                break;
            }
        }
        cout<<"Case #"<<z<<": "<<(flag?"YES":"NO")<<endl;
    }
}
