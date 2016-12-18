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
int lg2(int n){
    int lg2 = -1;
    int cur = 1;
    while(cur <= n){
        lg2++;
        cur <<= 1;
    }
    return lg2;
}
char str[1000][1000];
inline void join(int u, int v){
    str[u][v] = str[v][u] = 'Y';
}
int main()
{
    int k;
    in_I(k);
    int tot = 2 + lg2(k)*2;
    int pre = lg2(k);
    vector<int> aux;
    k -= 1<<(pre);
    int n = tot;
    while(k){
        int lg = lg2(k);
        int diff = pre - lg;
        aux.push_back(diff);
        n += diff;
        k -= (1<<lg);
    }
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            str[i][j] = 'N';
    if(pre == 0){
        join(0, 1);
    }else{
        for(int i = 1;i<=pre;i++){
            int top = 2*i;
            int down = top+1;
            if(i == 1){
                join(0, top);
                join(0, down);
            }else{
                join(2*(i-1), top);
                join(2*(i-1)+1, down);
                join(2*(i-1)+1, top);
                join(2*(i-1), down);
            }
            if(i == pre){
                join(1, top);
                join(1, down);
            }
        }
        int cnt = 2+2*pre;
        for(int i = 0;i<aux.size();i++){
            for(int j = 0;j<aux[i];j++, cnt++){
                if(j == 0){
                    join(0, cnt);
                }else{
                    join(cnt-1, cnt);
                }
            }
            if(aux[i] != pre)
            join(2*(aux[i]+1), cnt-1),
            join(2*(aux[i]+1)+1, cnt-1);
            else
                join(1, cnt-1);
        }
    }
    printf("%d\n", n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%c", str[i][j]);
        }
        newline;
    }
}
