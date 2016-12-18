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
int main()
{
    in_T{
        int n;
        in_I(n);
        bool flag = true;
        bool ans = true;
        long long arr[n+1];
        bool poss[n+1];
        poss[0] = poss[1] = true;
        arr[0] = 0;
        int max_neg_idx = -1;
        long long cur = 0;
        for(int i = 0;i<n;i++){
            in_L(arr[i+1]);
            if(arr[i+1] < 0 && flag){
                if(max_neg_idx == -1)
                    max_neg_idx = i+1;
                else if(arr[max_neg_idx] > arr[i+1])
                    max_neg_idx = i+1;
            }
            cur += arr[i+1];
            if(cur < 0)
                flag = false;
        }
        if(max_neg_idx != -1)
            arr[max_neg_idx] = -arr[max_neg_idx];
        cur = 0;
        for(int i = 1;i<=n;i++){
            cur += arr[i];
            if(cur < 0){
                printf("%d\n", i);
                ans = false;
                break;
            }
        }
        if(ans)
            printf("She did it!\n");
    }
}
