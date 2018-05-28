#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;

const int mod = 1000000007;
template <typename T>
inline T MUL(T a, T b) { return (a*1LL*b)%mod; }
template <typename T>
inline T ADD(T a, T b) { return (a+0LL+b)%mod; }

using namespace std;

long long compute(string &str){
    long long cur = 1;
    long long dmg = 0;
    for(char c: str){
        if(c == 'C')
            cur *= 2;
        else
            dmg += cur;
    }
    return dmg;
}

bool change(string &str){
    for(int i = 1; i < str.length(); i++){
        if(str[i] == 'S' && str[i-1] == 'C'){
            swap(str[i], str[i-1]);
            return true;
        }
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    for(int z = 1; z <= T; z++){
        int D;
        string P;
        cin>>D>>P;
        int ans = 0;
        while(1){
            if(compute(P) <= D) break;
            if(!change(P)) {ans = -1; break;}
            ans++;
        }
        cout<<"Case #"<<z<<": ";
        if(ans == -1)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ans<<endl;
    }
}
