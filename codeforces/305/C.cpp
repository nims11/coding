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
#define MAXN 600000
int phi[MAXN + 1], prime[MAXN/10], sz;
bitset <MAXN + 1> mark;
void gen(){ 
    for (int i = 2; i <= MAXN; i++ ){
        if(!mark[i]){
            phi[i] = i-1;
            prime[sz++]= i;
        }
        for (int j=0; j<sz && prime[j]*i <= MAXN; j++ ){
            mark[prime[j]*i]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]] = phi[i]*prime[j];
                break;
            }
            else phi[i*prime[j]] = phi[i]*(prime[j]-1 );
        }
    }
}

int BIT[600001];
int query(int idx, int n)
{
    int ret = 0;
    while(idx>0)
    {
        ret += BIT[idx];
        idx -= idx & -idx;
    }
    return ret;
}
void update(int idx, int n, int val)
{
    while(idx<=n)
    {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}
int main()
{
    gen();
    int n, q;
    in_I(n);
    in_I(q);
    int arr[n];
    int flag[n];
    for(int i = 0;i<n;i++){
        in_I(arr[i]);
        flag[i] = 0;
    }
    int res = 0;
    while(q--){
        int x;
        in_I(x);
        if(flag[x-1] == 0)
            flag[x-1] = 1, update(arr[x-1], MAXN, 1);
        else
            flag[x-1] = 0, update(arr[x-1], MAXN, -1);
    }
}
