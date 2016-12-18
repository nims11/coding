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

bool suitable(string &s, int x){
    int y = x;
    for(int i = s.length()-1;i>=0;i--){
        int c = s[i]-'0';
        // cout<<c<<" "<<x%10<<endl;
        if(c == x%10 || s[i] == '?'){
        
        }else
            return false;
        x /= 10;
    }
    return true;
}
int pow_10[5] = {0, 10, 100, 1000, 10000};
pair<string, string> solve(string &c, string &j){
    int len = c.length();
    int ans_c = 0, ans_j = 1e9;
    for(int i = 0;i<pow_10[len];i++){
        if(!suitable(c, i))continue;
        for(int k = 0;k<pow_10[len];k++){
            if(!suitable(j, k))continue;
            if(abs(i-k) < abs(ans_c-ans_j)){
                ans_c = i;
                ans_j = k;
            }
        }
    }
    string foo, bar;
    for(int i = 0;i<len;i++)
        foo.push_back('x'), bar.push_back('x');
    for(int i = len-1;i>=0;i--){
        foo[i] = ans_c%10;
        foo[i] += '0';
        bar[i] = ans_j%10;
        bar[i] += '0';
        ans_c/=10;
        ans_j/=10;
    }
    return {foo, bar};
}
int main(){
    int t, z;
    cin>>t;
    for(z = 1;z<=t;z++){
        string c, j;
        cin>>c>>j;
        pair<string, string> res = solve(c, j);
        cout<<"Case #"<<z<<": "<<res.first<<" "<<res.second<<endl;
    }
}
