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
int arr_x[500];
int arr_y[500];
#define MAX_SUM 126000
int field[126000];
int field2[126000];
int main(){
    in_T{
        char str[2];
        int n;
        in_I(n);
        int _y;
        in_I(_y);
        int cnt_x = 0;
        int cnt_y = 0;
        int xsum = 0;
        int ysum = 0;
        for(int i = 0;i<n;i++){
            in_S(str);
            if(i%2 == 0)
                in_I(arr_x[cnt_x++]);
            else
                in_I(arr_y[cnt_y++]);
        }
        if(n <= 2){
            printf("NO\n");
            continue;
        }
        int max_sum = 0;
        memset(field, 0, sizeof(field));
        field[0] = 1;
        for(int i = 0;i<cnt_x;i++){
            xsum += arr_x[i];
            int cnt = 0;
            for(int j = 0;j<=max_sum;j++){
                if(field[j]){
                    field2[cnt++] = j+arr_x[i];
                }
            }
            for(int j = 0;j<cnt;j++){
                field[field2[j]] = 1;
                max_sum = max(max_sum, field2[j]);
            }
        }

        int res_x = 0;
        for(int i = xsum/2;i>=0;i--){
            if(field[i]){
                res_x = xsum - 2*i;
                break;
            }
        }

        max_sum = 0;
        memset(field, 0, sizeof(field));
        field[0] = 1;
        for(int i = 0;i<cnt_y;i++){
            ysum += arr_y[i];
            int cnt = 0;
            for(int j = 0;j<=max_sum;j++){
                if(field[j]){
                    field2[cnt++] = j+arr_y[i];
                }
            }
            for(int j = 0;j<cnt;j++){
                field[field2[j]] = 1;
                max_sum = max(max_sum, field2[j]);
            }
        }

        int res_y = 1e9;
        for(int i = ysum/2;i>=0;i--){
            if(field[i]){
                res_y = min(abs(ysum - 2*i - _y), res_y);
            }
        }
        printf("%d\n", res_x+res_y);
    }
}
