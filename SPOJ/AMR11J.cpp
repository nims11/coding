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
/*
0 - unvisited
1 - greyed
2 - war
-1 = swamps
*/
struct node{
    int time;
    int st;
    int r,c;
}tmp,tmp2;
int foo1[] = {0,0,1,-1};
int foo2[] = {1,-1,0,0};
int main()
{
    in_T
    {
        int R,C;
        in_I(R);in_I(C);
        char grid[R][C+1];
        for(int i=0;i<R;i++)
            in_S(grid[i]);
        int visited[R][C];
        int time[R][C];
        queue <node> BFS;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                time[i][j] = 0;
                visited[i][j] = 0;
                if(grid[i][j]>='a' && grid[i][j]<='z')
                {
                    tmp.time=0;
                    visited[i][j] = grid[i][j];
                    tmp.r = i;
                    tmp.st = grid[i][j];
                    tmp.c = j;
                    BFS.push(tmp);
                }else if(grid[i][j]=='#')
                    visited[i][j] = -1;
            }
        }
        while(!BFS.empty())
        {
            tmp = BFS.front();
//            cout<<tmp.r<<" "<<tmp.c<<endl;
            BFS.pop();
            if(visited[tmp.r][tmp.c]==2)
            {
                continue;
            }
            for(int i=0;i<4;i++)
            {
                int r = tmp.r+foo1[i];
                int c = tmp.c+foo2[i];
                if(r<R && c<C && r>=0 && c>=0)
                {
                        if(visited[r][c] == 0){
                            time[r][c] = tmp.time+1;
                            visited[r][c] = tmp.st;
                            tmp2.r= r;
                            tmp2.c = c;
                            tmp2.time = tmp.time+1;
                            tmp2.st = tmp.st;
                            BFS.push(tmp2);
                        }
                        else if(visited[r][c]>='a' && visited[r][c]<='z' && visited[r][c]!=tmp.st)
                        {
                            if(time[r][c]==tmp.time+1)
                            {
                                visited[r][c] = 2;
                            }
                        }
                }
            }
        }
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(visited[i][j]>='a' && visited[i][j]<='z')
                {
                    printf("%c",visited[i][j]);
                }else if(visited[i][j] == -1)
                    printf("#");
                else if(visited[i][j] == 2)
                    printf("*");
                else if(!visited[i][j])
                    printf(".");

            }
            printf("\n");
        }
        printf("\n");

    }
}
