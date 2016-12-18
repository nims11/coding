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
int grid[104][104];
int row_max[104], col_max[104];
int main()
{
    int c =0;
    in_T
    {
        c++;
        cout<<"Case #"<<c<<": ";
        int n,m;
        in_I(n);in_I(m);
        for(int i=0;i<n;i++)
            row_max[i] = 0;
        for(int i=0;i<m;i++)
            col_max[i] = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                in_I(grid[i][j]);
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] != row_max[i] && grid[i][j] != col_max[j])
                {
                    flag = false;
                    i = n;
                    break;
                }
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
}
