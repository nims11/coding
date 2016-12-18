/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int main()
{
    int grid[205][205];
    in_T
    {
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        in_I(grid[i][j]);

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool flag=true;
                for(int k=0;k<n;k++)
                {
                    if(k!=i && k!=j)
                    {
                        if(grid[i][j]==grid[i][k]+grid[j][k])
                        {
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag)
                printf("%d %d\n",i+1,j+1);
            }
        }
    }
}
