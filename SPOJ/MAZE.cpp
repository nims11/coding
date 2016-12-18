/*
 * DP
 * The idea here is, to derive a recurrence for the solution. We check passability between each consecutive columns for the three rows. But there is a catch here
 * and only doing this will return a WA. We also need to check the connectivity between the consecutive rows for each column.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int n;
char grid[3][200001];
int main()
{
    bool foo[200001][3],connec_12[200001],connec_23[200001];
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
        {
            connec_12[i]=connec_23[i]=false;
            for(int j=0;j<3;j++)
            {
                in_I(grid[j][i]);
                foo[i][j]=false;
            }
        }
        foo[n][0]=foo[n][1]=foo[n][2]=true;
        connec_12[n]=connec_23[n]=false;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<3;j++)
            {
                foo[i][j]=false;
                switch(grid[j][i])
                {
                    case 1:foo[i][j]=foo[i+1][j];break;
                    case 2:
                    switch(j)
                    {
                        case 0:
                        if(grid[1][i]==2 && foo[i+1][1])foo[i][j]=true;
                        else if(grid[1][i]==1 && grid[2][i]==2)foo[i][j]=foo[i+1][2];
                        break;
                        case 1:
                        if(grid[0][i]==2 && foo[i+1][0])foo[i][j]=true;
                        else if(grid[2][i]==2)foo[i][j]=foo[i+1][2];
                        break;
                        case 2:
                        if(grid[1][i]==2 && foo[i+1][1])foo[i][j]=true;
                        else if(grid[1][i]==1 && grid[0][i]==2)foo[i][j]=foo[i+1][0];
                        break;
                    }
                    break;
                }
            }
            if(grid[0][i]==2 && grid[1][i]==2)
            {
                connec_12[i]=true;
            }else
            {
                if(grid[0][i]==1 && grid[1][i]!=0)
                connec_12[i]=connec_12[i+1];
            }
            if(grid[1][i]==2 && grid[2][i]==2)
            {
                connec_23[i]=true;
            }else
            {
                if(grid[1][i]==1 && grid[2][i]!=0)
                connec_23[i]=connec_23[i+1];
            }

            if(!foo[i][0])
            {
                if(grid[0][i]==1)
                {
                    if(foo[i][2])
                    {
                        if(connec_12[i])foo[i][0]=true;
                    }
                }
            }
            if(!foo[i][2])
            {
                if(grid[2][i]==1)
                {
                    if(foo[i][0])
                    {
                        if(connec_23[i])foo[i][2]=true;
                    }
                }
            }
        }
        if(foo[0][0]||foo[0][1]||foo[0][2])printf("yes\n");
        else printf("no\n");
    }
}
