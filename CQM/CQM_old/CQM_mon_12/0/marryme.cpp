/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
struct foo
{
    char ch;
    int val;
    int i,j;
    friend bool operator<(const foo &a,const foo &b)
    {
        return a.val<b.val;
    }
};
struct coord
{
    int i,j;
};
int main()
{
    int n;
    while(in_I(n)!=EOF)
    {
        int lll=0;
        char grid[23][23];
        coord v;
        foo kkk[5];
        for(int i=0;i<n;i++)
        {
            in_S(grid[i]);
        }
        for(int i=0;i<n;i++)
        for(int j=0;grid[i][j]!=0;j++)
        {
            switch(grid[i][j])
            {
                case 'V':v.i=i;v.j=j;break;
                case '.':break;
                case '#':break;
                default: kkk[lll].ch=grid[i][j];kkk[lll].i=i;kkk[lll++].j=j;break;
            }
        }
        int ansGrid[23][23];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            ansGrid[i][j]=1<<30;
            if(grid[i][j]=='#')ansGrid[i][j]=-1;
        }
        queue<coord> QUEUE;
        QUEUE.push(v);
        ansGrid[v.i][v.j]=0;
        while(!QUEUE.empty())
        {
            coord tmp=QUEUE.front();
			QUEUE.pop();
			if((tmp.i+1)<n && ansGrid[tmp.i+1][tmp.j]>ansGrid[tmp.i][tmp.j]+1)
			{
				ansGrid[tmp.i+1][tmp.j]=ansGrid[tmp.i][tmp.j]+1;
				coord y={tmp.i+1,tmp.j};
				QUEUE.push(y);
			}
			if((tmp.i-1)>=0 && ansGrid[tmp.i-1][tmp.j]>ansGrid[tmp.i][tmp.j]+1)
			{
				ansGrid[tmp.i-1][tmp.j]=ansGrid[tmp.i][tmp.j]+1;
				coord y={tmp.i-1,tmp.j};
				QUEUE.push(y);
			}
			if((tmp.j+1)<n && ansGrid[tmp.i][tmp.j+1]>ansGrid[tmp.i][tmp.j]+1)
			{
				ansGrid[tmp.i][tmp.j+1]=ansGrid[tmp.i][tmp.j]+1;
				coord y={tmp.i,tmp.j+1};
				QUEUE.push(y);
			}
			if((tmp.j-1)>=0 && ansGrid[tmp.i][tmp.j-1]>ansGrid[tmp.i][tmp.j]+1)
			{
				ansGrid[tmp.i][tmp.j-1]=ansGrid[tmp.i][tmp.j]+1;
				coord y={tmp.i,tmp.j-1};
				QUEUE.push(y);
			}
        }
        for(int i=0;i<lll;i++)
        {
            kkk[i].val=ansGrid[kkk[i].i][kkk[i].j];
        }
        sort(kkk,kkk+lll);
        if(kkk[0].val==1<<30)
        printf("Single forever!\n");
        else if(kkk[0].val==kkk[1].val)
        printf("Only the VC can decide now\n");
        else
        printf("%c %d\n",kkk[0].ch,kkk[0].val);
    }
}
