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
#define debug(a) cout<<#a<<" = "<<a<<endl;
int main(){
    int a, b, c, l;
    cin>>a>>b>>c>>l;
    long long res = 0;
    for(int diff = 0;diff <= 1000000;diff++){
        int min_a = max(0, diff+1-a);
        int val_a = min_a + a;
        if(val_a < a)continue;
        int val = 0;
        
doagain:
        // b > c
        {
            int min_c = max(0, (val_a-diff)/2 + 1 - c);
            int val_c = c + min_c;
            int min_b = diff+val_c-b;
            int val_b = min_b+b;
            if(min_b < 0){
                val_c += -min_b;
                min_c += -min_b;
                min_b = 0;
            }
            int rem_l = l - min_a - min_b - min_c;
            if(diff == 5){

                cout<<b<<" "<<c<<" "<<diff<<endl;
            cout<<val_a<<" "<<val_b<<" "<<val_c<<" "<<rem_l<<endl;
            cout<<min_a<<" "<<min_b<<" "<<min_c<<endl;
            cout<<endl<<endl;
            }
            if(min_b >= 0 && rem_l >= 0){
                cout<<b<<" "<<c<<" "<<diff<<endl;
            cout<<val_a<<" "<<val_b<<" "<<val_c<<" "<<rem_l<<endl;
            cout<<min_a<<" "<<min_b<<" "<<min_c<<endl;
                int fin_x = (rem_l - (val_b+val_c-val_a-1))/2;
                if(fin_x%2 != 1)fin_x--;
                fin_x /= 2;
                debug(fin_x);
                fin_x = max(fin_x, -1);
                if(fin_x>=0)
                res += (val_b+val_c-val_a)*1LL*(fin_x+1) + fin_x*1LL*(fin_x+1);

                int fin_y = (rem_l)/2;
                int y = fin_y - fin_x;
                res += y*1LL*(rem_l-2*fin_x+1)-y*1LL*(y+1);
            cout<<res<<endl;
            cout<<endl;
            }
        }
        val++;
        if((b == c && diff == 0))continue;
        swap(b, c);
        if(val < 2)
            goto doagain;
    }
    cout<<res<<endl;
}
