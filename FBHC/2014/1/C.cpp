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
#include<cassert>
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
int N, M;
struct node{
    int from_top, from_left, from_src;
    int to_dest, to_bot, to_right;
}nodes[501][501];
char grid[502][502];
void bfs_src()
{
    nodes[0][0].from_src = nodes[0][0].from_left = nodes[0][0].from_top = (grid[0][0] == '.');
    for(int i = 1;i<M;i++){
        if(grid[0][i] == '#') nodes[0][i].from_left = 0;
        else    nodes[0][i].from_left = 1*(nodes[0][i-1].from_left != 0) + nodes[0][i-1].from_left;
        nodes[0][i].from_top = 0;
        nodes[0][i].from_src = nodes[0][i].from_left;
    }
    for(int i = 1;i<N;i++){
        if(grid[i][0] == '#') nodes[i][0].from_top = 0;
        else    nodes[i][0].from_top = 1*(nodes[i-1][0].from_top != 0) + nodes[i-1][0].from_top;
        nodes[i][0].from_left = 0;
        nodes[i][0].from_src = nodes[i][0].from_top;
    }
    for(int i = 1;i<N;i++)
    for(int j = 1;j<M;j++){
        if(grid[i][j] == '#') nodes[i][j].from_top = nodes[i][j].from_left = nodes[i][j].from_src = 0;
        else{
            nodes[i][j].from_left = 1*(nodes[i][j-1].from_src != 0) + nodes[i][j-1].from_src;
            nodes[i][j].from_top = 1*(nodes[i-1][j].from_src != 0) + nodes[i-1][j].from_src;
            nodes[i][j].from_src = max(nodes[i][j].from_left, nodes[i][j].from_top);
        }
    }
}
void bfs_dest(){
    for(int i = N-1; i>=0;i--){
        for(int j = M-1; j>=0;j--){
            if(grid[i][j] == '#') nodes[i][j].to_dest = nodes[i][j].to_bot = nodes[i][j].to_right = 0;
            else{
                if(i+1 >= N) nodes[i][j].to_bot = 1;
                else nodes[i][j].to_bot = 1 + nodes[i+1][j].to_dest;
                if(j+1 >= M) nodes[i][j].to_right = 1;
                else nodes[i][j].to_right = 1 + nodes[i][j+1].to_dest;
                nodes[i][j].to_dest = max(nodes[i][j].to_bot, nodes[i][j].to_right);
            }
        }
    }
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cin>>N>>M;
        for(int i = 0;i<N;i++) in_S(grid[i]);
        bfs_src();
        bfs_dest();
        int res = 0;
        for(int i = 0;i<N;i++)for(int j = 0;j<M;j++){
            int from_src = nodes[i][j].from_src;
            if(from_src == 0)continue;
            int from_left = nodes[i][j].from_left, from_top = nodes[i][j].from_top;
            if(from_left){
                int cur = from_left;
                for(int k = i; k>=0 && grid[k][j] == '.';k--, cur++)
                    res = max(res, cur+nodes[k][j].to_right-1);
            }
            if(from_top){
                int cur = from_top;
                for(int k = j; k>=0 && grid[i][k] == '.'; k--, cur++)
                    res = max(res, cur+nodes[i][k].to_bot-1);
            }
        }
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
}
