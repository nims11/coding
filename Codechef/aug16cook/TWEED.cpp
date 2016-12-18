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
int arr[60];
int main(){
    in_T{
        int n;
        char str[10];
        in_I(n);
        in_S(str);
        for(int i = 0;i<n;i++)
            in_I(arr[i]);
        if(str[1] == 'u'){
            printf("Dum\n");
        }else{
            if(n == 1 && arr[0] % 2 == 0){
                printf("Dee\n");
            }else
                printf("Dum\n");
        }
    }
}
