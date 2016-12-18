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
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int res = 0;
        int inc = 0;
        int dec = 0;
        for(int i = 0;i<str.size();i++){
            res = res+str[i]-'0';
            inc += 9-str[i]+'0';
            if(i == 0 && str.size() != 1)
                dec += str[i]-'0'-1;
            else
            dec += str[i]-'0';
        }
        res %= 9;
        int ans = 100;
        if(inc >= 9-res)
            ans = min(ans, 9-res);
        if(dec >= res)
            ans = min(ans, res);
        cout<<ans<<endl;
    }
}
