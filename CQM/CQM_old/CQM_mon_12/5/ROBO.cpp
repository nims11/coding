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
#include<stack>
#include<utility>
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
int main()
{
    int grid[31][31];
    int visited[31][31];
    in_T
    {
        int r,c;
        int si,sj,di,dj;
        scanf("%d%d%d%d%d%d",&r,&c,&si,&sj,&di,&dj);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                visited[i][j] = 0;
        string str;
        for(int i=0;i<r;i++)
        {
            cin>>str;
            for(int j =0;j<str.length();j++)
            if(str[j] == 'A')grid[i][j] = 1;
            else grid[i][j] = 0;
        }
        queue<pair<int,int> > BFS;
        BFS.push(make_pair(si,sj));
        pair<int,int> tmp;
        visited[si][sj] = 1;
        int mini=si,minj=sj;
        int mindist = abs(si-di) + abs(sj-dj);
        while(!BFS.empty())
        {
            tmp = BFS.front();
            BFS.pop();
            int i = tmp.first, j =tmp.second;
            int dist = abs(di-i) + abs(dj-j);
            if(dist<mindist)
            {
                mindist = dist;
                mini = i;
                minj = j;
            }
            if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1])
            {
                visited[i][j-1] = visited[i][j] + 1;
                BFS.push(make_pair(i,j-1));
            }
            if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j])
            {
                visited[i-1][j] = visited[i][j] + 1;
                BFS.push(make_pair(i-1,j));
            }
            if(i+1<r && !visited[i+1][j] && grid[i+1][j])
            {
                visited[i+1][j] = visited[i][j] + 1;
                BFS.push(make_pair(i+1,j));
            }
            if(j+1<c && !visited[i][j+1] && grid[i][j+1])
            {
                visited[i][j+1] = visited[i][j] + 1;
                BFS.push(make_pair(i,j+1));
            }
        }
        cout<<mini<<" "<<minj<<endl;
        cout<<visited[mini][minj]-1<<(t?"\n":"");
    }
}
