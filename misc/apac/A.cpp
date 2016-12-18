#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int ge(int n, long long k, long long sz){
    // cout<<n<<" "<<k<<" "<<sz<<endl;
    if(n == 0)return 0;
    if(k == (sz+1)/2)return 0;
    if(k < (sz+1)/2)return ge(n-1, k, sz/2);
    return !ge(n-1, (sz-k+1), sz/2);
}
int getans(long long K){
    vector<long long> sizes;
    sizes.push_back(0);
    long long tot = 0;
    long long pre = 0;
    while(pre < K){
        sizes.push_back(pre+1+pre);
        pre = pre+1+pre;
    }
    return ge(sizes.size()-1, K, pre);
}
int main(){
    int z = 0;
    in_T{
        long long K;
        cin>>K;
        cout<<"Case #"<<(++z)<<": "<<getans(K)<<endl;
    }
}

int foo(char rnn[20]){
}
