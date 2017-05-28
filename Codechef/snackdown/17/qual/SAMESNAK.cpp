#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int main(){
    in_T{
        int x_11, x_12, y_11, y_12;
        in_I(x_11);
        in_I(y_11);
        in_I(x_12);
        in_I(y_12);
        int x_21, x_22, y_21, y_22;
        in_I(x_21);
        in_I(y_21);
        in_I(x_22);
        in_I(y_22);

        if(x_11 == x_12)
            swap(x_11, y_11), swap(x_12, y_12), swap(x_21, y_21), swap(x_22, y_22);
        if(x_11 > x_12)
            swap(x_11, x_12);
        if(x_21 > x_22)
            swap(x_21, x_22);
        if(y_11 > y_12)
            swap(y_11, y_12);
        if(y_21 > y_22)
            swap(y_21, y_22);

        if(y_21 == y_22){
            if(y_21 != y_11){
                printf("no\n");
                continue;
            }
            if(x_11 <= x_21 && x_21 <= x_12)
                printf("yes\n");
            else if(x_21 <= x_11 && x_11 <= x_22)
                printf("yes\n");
            else
                printf("no\n");
        }else{
            if((x_21 == x_11 || x_21 == x_12) && (y_11 == y_21 || y_11 == y_22))
                printf("yes\n");
            else if(x_11 <= x_21 && x_21 <= x_12 && y_22 == y_21 && y_22 == y_11)
                printf("yes\n");
            else if(x_11 == x_12 && x_11 == x_21 && (y_21 <= y_11 && y_11 <= y_22))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
}
