/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;

int R, C, N;
int getans1(){
    int s1 = C/2;
    int s2 = C/2+(C%2);
    int grid[R][C];
    int opt = 0, opt2 = 0;
    int optval1 = 2 - (R == 1 || C == 1);
    int optval2 = 3 - (R == 1 || C == 1);
    int N2 = N;
    for(int i = 0;i<R;i++)
        for(int j = 0;j<C;j++){
            if(i == 0 && j == 0)
                grid[i][j] = 0;
            else if(j != 0)
                grid[i][j] = !grid[i][j-1];
            else
                grid[i][j] = !grid[i-1][j];
            if(grid[i][j] == 0)
                if(i == 0 || i == R-1 || j == 0 || j == C-1){
                    if((i == 0  || i == R-1) &&(j == 0 || j == C-1) && grid[i][j] == 0)
                        opt++;
                    else
                        opt2++;
                }
            if(grid[i][j] == 1)
                N = max(0, N-1);
        }
    int ans = 0;
    ans = min(opt, N)*optval1 + min(opt2, max(0, N-opt))*optval2 + max(N-opt-opt2, 0)*4;
    opt = opt2 = 0;
    N = N2;
    for(int i = 0;i<R;i++)
        for(int j = 0;j<C;j++){
            if(i == 0 && j == 0)
                grid[i][j] = 1;
            else if(j != 0)
                grid[i][j] = !grid[i][j-1];
            else
                grid[i][j] = !grid[i-1][j];

            if(grid[i][j] == 0)
                if(i == 0 || i == R-1 || j == 0 || j == C-1){
                    if((i == 0  || i == R-1) &&(j == 0 || j == C-1) && grid[i][j] == 0)
                        opt++;
                    else
                        opt2++;
                }
            if(grid[i][j] == 1)
                N = max(0, N-1);
        }

    ans = min(ans, min(opt, N)*optval1 + min(opt2, max(0, N-opt))*optval2 + max(N-opt-opt2, 0)*4);
    return ans;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        in_I(R);in_I(C);in_I(N);
        int ans = getans1();
        cout<<"Case #"<<z<<": "<<ans<<endl;
    }
}
