#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int R, C;
char grid[101][101];
int vis[101][101];
const char str[] = "ALLIZZWELL";
bool dfs(int x, int y, int idx){
    vis[x][y] = 1;
    for(int i = -1;i<=1;i++){
        int xx = x+i;
        if(xx > 0  && xx <= R)
            for(int j = -1;j<=1;j++){
                int yy = y+j;
                if(yy > 0 && yy <= C && vis[xx][yy] == 0 && str[idx+1] == grid[xx][yy]){
                    if(str[idx+2] == 0){
                        return true;
                    }
                    else if(dfs(xx, yy, idx+1))
                        return true;
                }
            }
    }
    vis[x][y] = 0;
    return false;
}
bool dfs(){
    for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            if(grid[i][j] == 'A')
                if(dfs(i, j, 0))
                    return true;
        }
    }
    return false;
}
int main(){
    in_T{
        in_I(R);in_I(C);
        for(int i = 1;i<=R;i++)
            in_S(grid[i]+1);
        for(int i = 1; i<=R;i++)
            for(int j = 1;j<=C;j++)
                vis[i][j] = 0;
        printf(dfs()?"YES\n":"NO\n");
    }
}
