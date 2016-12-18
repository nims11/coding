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
char grid[12];
int main()
{
    in_T
    {
        for(int i=0;i<3;i++)
        scanf("%s",grid+3*i);
        bool flag=true;
        int x,o,xwin,owin;
        x=o=xwin=owin=0;
        for(int i=0;i<9;i++)
        {
            if(grid[i]=='X')x++;
            else if(grid[i]=='O')o++;
        }
        if(x==o || x==o+1)
        {
            for(int i=0;i<3;i++)
            {
                if(grid[i*3]==grid[i*3+1] && grid[i*3+2]==grid[i*3])
                {
                    if(grid[i*3]=='X')xwin++;
                    else if(grid[i*3]=='O')owin++;
                }
            }
            for(int i=0;i<3;i++)
            {
                if(grid[i]==grid[3+i] && grid[6+i]==grid[i])
                {
                    if(grid[i]=='X')xwin++;
                    else if(grid[i]=='O')owin++;
                }
            }
            if(grid[0]==grid[4] && grid[0]==grid[8])
            {
                if(grid[0]=='X')xwin++;
                else if(grid[0]=='O')owin++;
            }
            if(grid[2]==grid[4] && grid[4]==grid[6])
            {
                if(grid[4]=='X')xwin++;
                else if(grid[4]=='O')owin++;
            }
            if(xwin>0 && owin>0)
            {
                flag=false;
            }else
            {
                if(xwin)
                {
                    if(x==o){flag=false;}
                }else if(owin)
                {
                    if(x!=o){flag=false;}
                }
            }
        }else
        flag=false;
        if(flag)cout<<"yes\n";
        else cout<<"no\n";
    }
}

