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
long long dp[201][10];
vector<int> ch = {1, 2, 5, 10, 20, 50, 100, 200};
long long getans(int n, int c){
    if(c == 8){
        return (n == 0);
    }
    if(dp[n][c] != -1)
        return dp[n][c];
    long long &ret = dp[n][c];
    ret = 0;
    for(int x = n;x>=0;x-=ch[c]){
        ret += getans(x, c+1);
    }
    return ret;
}
int main()
{
    for(int i = 0;i<201;i++)
        for(int j = 0;j<10;j++)
            dp[i][j] = -1;

    cout<<getans(200, 0)<<endl;
}
