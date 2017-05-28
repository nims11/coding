#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
long strongRelation(int n, int m) {
    long ans = 1;
    int adj[500][500] = {0};
    long long nn = n;
    long long mm = m;
    while(mm > 0){
        int x = n - (ans == n/2 && n % 2 == 0?n/2:0);
        for(int i = 0;i<x;i++){
            adj[i][(x+i)%n] = 1;
            adj[(x+i)%n][i] = 1;
        }
        mm -= x;
        ans++;
    }
     ans = 1;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(!adj[i][j])
                goto xxx;
        }
        ans++;
    }
    xxx:
    return ans;
}
int main(){
    cout<<strongRelation(3, 2)<<endl;
}
