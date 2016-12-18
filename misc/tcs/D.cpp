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
vector<long long> arr;
set<long long> contains;
int main(){
    int N;
    in_I(N);
    while(N--){
        long long x;
        in_L(x);
        arr.push_back(x);
    }
    long long X;
    in_L(X);
    for(int i = 0;i<(int)arr.size();i++){
        if(contains.find(X-arr[i]) != contains.end()){
            printf("True");
            return 0;
        }
        for(int j = 0;j<i;j++)
            contains.insert(arr[i]+arr[j]);
    }
    printf("False");
    return 0;
}
