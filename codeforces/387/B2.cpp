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
    int x[3], y[3];
    for(int i = 0;i<3;i++)
        cin>>x[i]>>y[i];
    printf("3\n");
    for(int i = 0;i<3;i++){
        int mid_x = 0, mid_y = 0;
        for(int j = 0;j<3;j++){
            if(i != j)
                mid_x += x[j],  mid_y += y[j];
        }
        printf("%d %d\n", mid_x - x[i], mid_y - y[i]);
    }
}
