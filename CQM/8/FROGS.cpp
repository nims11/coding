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
int vis[1001];
int grph[1001];
int dfs(int i){
    if(vis[i])
        return 0;
    vis[i] = 1;
    if(grph[i] == i)
        return 0;
    return 1+dfs(grph[i]);
}
long long GCD(long long a,long long b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
long long LCM(long long a, long long b){
    return a*b/GCD(a, b);
}
int main()
{
    in_T{
        int n;
        in_I(n);
        for(int i = 1;i<=n;i++){
            in_I(grph[i]);
            vis[i] = 0;
        }
        long long lcm = 1;
        bool flag = false;
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                int x = dfs(i);
                if(x != 0){
                    flag = true;
                    lcm = LCM(lcm, x);
                }
            }
        }
        printf("%lld\n", lcm);
    }
}
