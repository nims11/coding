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
int getCompleteGraphLen(long long x){
    long long cur = 1;
    int ans = 0;
    while(cur <= x){
        cur *= 2;
        ans++;
    }
    return ans-1;
}
int main(){
    int z, t;
    cin>>t;
    for(z=1;z<=t;z++){
        int graph[100][100] = {0};
        int B;
        long long M;
        cin>>B>>M;
        int completeGraphLen = getCompleteGraphLen(M);
        long long rem = M - (1LL<<completeGraphLen);
        if(completeGraphLen + bool(rem) > B-2){
            cout<<"Case #"<<z<<": IMPOSSIBLE"<<endl;
            continue;
        }
        for(int i = 0;i<completeGraphLen+1;i++){
            for(int j = i+1;j<completeGraphLen+1;j++){
                graph[i][j] = 1;
            }
            graph[i][B-1] = 1;
        }
        int cur = 1;
        while(rem){
            graph[completeGraphLen+1][B-1] = 1;
            if(rem&1){
                graph[cur][completeGraphLen+1] = 1;
            }
            rem/=2;
            cur++;
        }
        cout<<"Case #"<<z<<": POSSIBLE"<<endl;
        for(int i = 0;i<B;i++){
            for(int j = 0;j<B;j++){
                cout<<graph[i][j];
            }
            cout<<endl;
        }
    }
}
