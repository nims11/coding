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
int n, m;
string feat[110];
int grid[110][110];
int carry[110][110];
int orig[110];
// int getans(int x, int y, int mode=-1){
//     int ret = 0;
//     int diff = 0;
//     if(grid[x][y] != carry[x][y]){
//         ret++;
//         diff = grid[x][y]-carry[x][y];
//     }
//     if(x > 0){
//         carry[x-1][y] += grid[x][y];
//         if(mode == -1 || mode == 0)
//             ret += getans(x-1, y, 0);
//     }
//     if(y > 0){
//         if()
//         else
//             carry[x][y-1] += grid[x][y];
//         if(mode == -1 || mode == 1)
//         ret += getans(x, y-1, 1);
//     }
//     if(mode == -1 && x>0 && y > 0)
//         ret += getans(x-1, y-1);
//     return ret;
// }
int main()
{
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        cin>>feat[i];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++){
            carry[i][j] = 0;
            if(feat[i][j] == 'B')
                grid[i][j] = -1;
            else
                grid[i][j] = 1;
        }
    int res = 0;
    for(int j = m-1;j>=0;j--){
        for(int i = n-1;i>=0;i--){
            int diff = 0;
            carry[i][j] += orig[i];
            if(carry[i][j] != grid[i][j]){
                res++;
                diff = grid[i][j]-carry[i][j];
                orig[i] += diff;
            }
            if(i > 0)
                carry[i-1][j] += grid[i][j];
        }
    }
    cout<<res<<endl;
    // cout<<getans(n-1, m-1)<<endl;
    // for(int i = 0;i<n;i++)
    //     for(int j = 0;j<m;j++)
    //         cout<<carry[i][j]<<" ";
}
