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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int arr[2000];
int main()
{
    in_T{
        int N;
        in_I(N);
        for(int i = 0;i<N;i++){
            in_I(arr[i]);
            arr[i] = -arr[i];
        }
        sort(arr, arr+N);
        int res = 0;
        for(int i = 0;i<N;i++){
            if(i%4 < 2)
                res -= arr[i];
        }
        printf("%d\n", res);
    }
}
