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
int main()
{
    int N;
    in_I(N);
    char str[N+2];
    in_S(str);
    int res = 0;
    bool foo = true;
    int r = 0, b = 0;
    for(int i = 0;i<N;i++)
        r += (str[i] == 'r'), b += (str[i] == 'b');
    foo = (r && b);
    if(!foo){
        printf("%d\n", N);
        return 0;
    }
    for(int i = 0;i<=N;i++){
        int cur = i%N, prev = (i-1+N)%N;
        int tot = 0;
        int idx = cur;
        int col = str[cur];
        while(str[idx] == col || col == 'w' || str[idx] == 'w'){
            if(col == 'w' && str[idx] != 'w')
                col = str[idx];
            tot++;
            idx++;
            idx %= N;
        }
        idx = prev;
        col = str[prev];
        while(str[idx] == col || col == 'w' || str[idx] == 'w'){
            if(col == 'w' && str[idx] != 'w')
                col = str[idx];
            tot++;
            idx = (idx-1+N)%N;
        }
        res = max(res, tot);
    }
    printf("%d\n", res);
}
