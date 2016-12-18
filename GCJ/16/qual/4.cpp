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
long long pow_1(int K, int C){
    long long ret = 1;
    for(int i = 1;i<=C;i++)
        ret *= K;
    return ret;
}
vector<long long> getres(int K, int C){
    vector<long long> res;
    long long st = 0;
    long long sz = pow_1(K, C);
    for(int i = 0;i<K;i++){
        st += sz/K*i;
        sz /= K;
        if(sz == 1 || i == K-1){
            res.push_back(st++);
            sz = pow_1(K, C);
            st = 0;
        }
    }
    return res;
}
int main(){
    int z = 0;
    in_T{
        int K, C, S;
        in_I(K);
        in_I(C);
        in_I(S);

        cout<<"Case #"<<++z<<": ";
        vector<long long> res = getres(K, C);
        if(S < res.size())
            cout<<"IMPOSSIBLE"<<endl;
        else{
            for(long long i: res)
                cout<<i+1<<" ";
            cout<<endl;
        }
    }
}
