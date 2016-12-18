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

char grid[30][30];
int foo[30][30];
int r,c;
int bar[]={0,0,1,-1};
int qux[]={1,-1,0,0};
void getans(int m,int n)
{
    for(int i=0;i<4;i++)
    {
        int x=m+bar[i],y=n+qux[i];
        if(x<r && y<c && x>=0 && y>=0 && grid[x][y]!='X' && foo[m][n]+grid[x][y]-'0'<foo[x][y])
        {
            foo[x][y]=foo[m][n]+grid[x][y]-'0';
            getans(x,y);
        }
    }
}
int main()
{
    while(1)
    {
        in_I(c);in_I(r);
        if(r==0)return 0;
        int starti,startj,endi,endj;
        for(int i=0;i<r;i++)
        {
            in_S(grid[i]);
            for(int j=0;j<c;j++)
            if(grid[i][j]=='S')starti=i,startj=j;
            else if(grid[i][j]=='D')endi=i,endj=j;
        }
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        foo[i][j]=1<<30;
        foo[starti][startj]=0;
        grid[starti][startj]=grid[endi][endj]='0';
        getans(starti,startj);
        printf("%d\n",foo[endi][endj]);
    }

}
