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
int n, m, W[600];
int curPos[600];
int curStack[600];
int main()
{
    in_I(n);in_I(m);
    for(int i = 0;i<n;i++)
        in_I(W[i]), curPos[i] = -1;
    int cnt = 0;
    long long res = 0;
    int x;
    for(int i = 0;i<m;i++){
        in_I(x);
        x--;
        if(curPos[x] == -1){
            curPos[x] = cnt++;
            curPos[x] = 0;
            for(int j = cnt-2;j>=0;j--)
                res += W[curStack[j]], curStack[j+1] = curStack[j], curPos[curStack[j]]++;
            curStack[0] = x;
        }else{
            for(int j = curPos[x]-1;j>=0;j--){
                res += W[curStack[j]], curStack[j+1] = curStack[j], curPos[curStack[j]]++;
            }
            curStack[0] = x;
            curPos[x] = 0;
        }
    }
    printf("%lld\n", res);
}
