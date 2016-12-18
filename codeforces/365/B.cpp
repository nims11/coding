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

int c[100010];
int cap[100010];
int main(){
    int n, k;
    in_I(n);
    in_I(k);
    for(int i = 0;i<n;i++){
        in_I(c[i]);
    }
    long long capsum = 0, capsum2 = 0;
    for(int i = 0;i<k;i++){
        int x;
        in_I(x);
        x--;
        cap[x] = 1;
        capsum += c[x];
        capsum2 += c[x]*c[x];
    }

    long long res = 0;
    for(int i = 0;i<n;i++){
        long long locsum = 0;
        if(cap[i]){
        }else{
            locsum += capsum;
            if(!cap[(i+1)%n])
                locsum += c[(i+1)%n];
            res += locsum*c[i];
        }
    }
    res += (capsum*capsum - capsum2)/2;
    cout<<res<<endl;
}
