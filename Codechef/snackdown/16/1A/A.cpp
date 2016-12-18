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
int arr[100100];
int N;
bool check1(){
    for(int i = 0;i<N-2;i++)
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2])
            return true;
    return false;
}
int main(){
    in_T{
        in_I(N);
        for(int i = 0;i<N;i++)
            in_I(arr[i]);
        if(check1()){
            printf("Yes\n");
        }
        else printf("No\n");
    }
}
