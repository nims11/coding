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
int n;
int grid[13][13];
int getans(int i, int j)
{
    if(i == n-1 && j == n-1)
    {
        int u = 1;
            for(int x=1;x<n;x++)
        {
            for(int y=0;y<x;y++)
            {
                u |= 1<<grid[x][y];
            }
        }
            if(u!= (1<<(n-1))-1)
        return 0;

        for(int x=1;x<n;x++)
        {
            for(int y=0;y<x;y++)
            {
                for(int z=0;z<n;z++)
                    if(grid[x][y]>max(grid[x][z], grid[z][y]))
                    return 0;
            }
        }

//                for(int x=1;x<n;x++)
//        {
//            for(int y=0;y<x;y++)
//            {
//                cout<<grid[x][y]<<" ";
//            }
//            newline;
//        }
//        int x;
//        cin>>x;
        return 1;
    }
    int ret = 0;
    for(int z=1;z<=n-2;z++)
    {
        grid[i][j] = grid[j][i] = z;
        if(i == n-1 && j == n-2)
        {
            ret += getans(n-1, n-1);
        }else if(j == i-1)
        {
            ret += getans(i+1, 0);
        }else
            ret += getans(i, j+1);
    }
    return ret;
}

int main()
{
    cin>>n;
        cout<<getans(1, 0)<<endl;
}
