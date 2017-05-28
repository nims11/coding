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
    int z = 0;
    in_T{
        z++;
        char str[1010];
        int k;
        in_S(str);
        in_I(k);
        int len = strlen(str);
        int ans = 0;
        for(int i = 0;i<len;i++){
            if(str[i] == '-'){
                ans++;
                if(i+k > len){
                    ans = -1;
                    break;
                }
                for(int j = i;j<i+k;j++){
                    str[j] = (str[j] == '+'?'-':'+');
                }
            }
        }
        cout<<"Case #"<<z<<": ";
        if(ans == -1)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ans<<endl;
    }
}
