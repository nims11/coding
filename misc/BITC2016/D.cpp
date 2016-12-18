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
int dp[401][401][3];
int dp_res[401][401];
int inf = 1e9;
int main(){
    int t;
    cin>>t;
    while(t--);
    {
        for(int i = 0;i<=400;i++)
            for(int j = 0;j<=400;j++){
                for(int k = 0;k<3;k++)
                    dp[i][j][k] = inf;
            }

        int grid[401][401];
        int n;
        in_I(n);
        map<string, int> foo;
        int cnt = 0;
        string str;
        int s;
        for(int i = 0;i<n;i++){
            cin>>str>>s;
            if(foo.find(str) == foo.end()){
                foo[str] = cnt++;
            }
            grid[foo[str]][s] = 1;
        }
        
        for(int i = 0;i<=400;i++){
            for(int j = 0; j<=400;j++){
                if(grid[i][j] == 0)
                    dp[i][j][0] = ((i>0 && j>0)?dp_res[i-1][j-1]:0);
                else
                    dp[i][j][0] = inf;
            }
        }
    }
}
