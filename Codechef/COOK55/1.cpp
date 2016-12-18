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
        int B;
        in_I(B);
        if(B == 1){
            printf("%d\n", 0);
            continue;
        }else if(B%2 == 1)
            B--;
        int res = 0;
        for(int i = B;i>0;i-=2){
            res += (i-2)/2;
        }
        printf("%d\n", res);
    }
}
