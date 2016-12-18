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
int sqrt1(int n)
{
    int x = sqrt(n);
    if(x*x == n)
        return x;
    if((x+1)*(x+1) == n)
        return x+1;
    if((x-1)*(x-1) == n)
        return x-1;
}
int main()
{
    string str;
    while(cin>>str)
    {
        int n = sqrt1(str.length());
        char grid[n][n];
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                grid[j][i] = str[cnt++];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!='_')
                cout<<grid[i][j];
            }
        }
        cout<<endl;
    }
}
