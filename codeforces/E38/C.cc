#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;
int sq(int x){
    int ret = sqrt(x);
    for(int i = ret - 1;i <=ret+1; i++)
        if(ret *ret == x)return ret;
    return 0;
}
int main(){
    in_T{
        long long x;
        in_L(x);
        long long n =-1, m = -1;
        for(long long i = 1; ; i++){
            long long rem = i*i - x;
            if(rem <= 0)continue;
            long long m1 = sqrt(i*i/rem);
            if(m1 == 1 && x != 0)
                break;
            /* cout<<i<<" "<<rem<<" "<<m1<<endl; */
            /* if(m1 > i)break; */
            while(m1> 0 && (i/m1)*(i/m1) >= rem){
                if((i/m1)*(i/m1) == rem){
                    m = m1;
                    n = i;
                    break;
                }
                m1--;
            }
            if(n != -1)break;
        }
        if(m == -1)
            cout<<-1<<endl;
        else
            cout<<n<<" "<<m<<endl;
    }
}
