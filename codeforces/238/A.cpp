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
int n,x;
//int row[1010], col[1010];
int grid[1001][1001];
int contrib[1001][4];
int contribC[1001][4];
//int tot = 0;
int flipr[1001], flipc[1001];
int diags = 0;
int main()
{
    in_I(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            in_I(x);
            grid[i][j] = x;
            if(x && i == j)diags++;
//            if(x)row[i], col[j]++, tot++;
        }
    }
//    int ans = 0;
//    for(int i = 0;i<n;i++){
//        for(int j = 0;j<n;j++){
//            if(i == j)continue;
//            contrib[i][0] += grid[i][j]*grid[j][i];
//            contrib[i][1] += (1-grid[i][j])*(i!=j?grid[j][i]:(1-grid[j][i]));
//            contrib[i][2] += (i!=j?grid[i][j]:(1-grid[i][j]))*(1-grid[j][i]);
//            contrib[i][3] += (1-grid[i][j])*(1-grid[j][i]);
//
//            contribC[j][0] += grid[i][j]*grid[j][i];
//            contribC[j][1] += (1-grid[i][j])*(i!=j?grid[j][i]:(1-grid[j][i]));
//            contribC[j][2] += (i!=j?grid[i][j]:(1-grid[i][j]))*(1-grid[j][i]);
//            contribC[j][3] += (1-grid[i][j])*(1-grid[j][i]);
//        }
//        ans += contrib[i][0];
//    }
    int q;
    in_I(q);
    while(q--){
        int t;
        in_I(t);
        if(t == 1){ // row
            in_I(x);
            x--;
            flipr[x]^=1;
            if(flipr[x] ^ grid[x][x])
                diags++;
            else
                diags--;
        }else if(t == 2){   // col
            in_I(x);
            x--;
            flipc[x]^=1;
            if(flipc[x] ^ grid[x][x])
                diags++;
            else
                diags--;
        }else{
            printf("%d", (diags)%2);
        }
    }
    newline;
}
