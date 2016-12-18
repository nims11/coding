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

long long diff(string x, string y){
    if(x < y)
        swap(x, y);
    long long xx = 0, yy = 0;
    for(char c: x)
        xx = xx*10 + (c-'0');
    for(char c: y)
        yy = yy*10 + (c-'0');
    return xx-yy;
}
pair<string, string> solve(string c, string j){
    int len = c.length();
    if(len == 0){
        return {c, j};
    }
    if(c[0] != '?' && j[0] != '?'){
        if(c[0] > j[0]){
            for(int i = 1;i<len;i++){
                if(c[i] == '?')
                    c[i] = '0';
                if(j[i] == '?')
                    j[i] = '9';
            }
        }else if(c[0] < j[0]){
            for(int i = 1;i<len;i++){
                if(j[i] == '?')
                    j[i] = '0';
                if(c[i] == '?')
                    c[i] = '9';
            }
        }else if(len != 1){
            pair<string, string> res = solve(c.substr(1), j.substr(1));
            for(int i = 0;i<res.first.size();i++)
                c[i+1] = res.first[i];
            for(int i = 0;i<res.second.size();i++)
                j[i+1] = res.second[i];
        }
    }else{
        string ans_c, ans_j;
        int xxx = 0;
        while(xxx < c.length() && c[xxx] == '?' && j[xxx] == '?'){
            c[xxx] = j[xxx] = '0';
            xxx++;
        }
        char orig_c = c[xxx], orig_j = j[xxx];
        for(int x = 0;x<10;x++){
            for(int y = 0;y<10;y++){
                if(orig_c == '?'){
                    c[xxx] = x+'0';
                }
                if(orig_j == '?'){
                    j[xxx] = y+'0';
                }
                if(x == y && x != 0 && orig_j == orig_c && orig_j == '?')
                    continue;
                pair<string, string> res = solve(c.substr(xxx), j.substr(xxx));
                res.first = c.substr(0, xxx) + res.first;
                res.second = j.substr(0, xxx) + res.second;
                if(ans_c.length() == 0){
                    ans_c = res.first;
                    ans_j = res.second;
                }else if(diff(ans_c, ans_j) > diff(res.first, res.second)){
                    ans_c = res.first;
                    ans_j = res.second;
                }else if(diff(ans_c, ans_j) == diff(res.first, res.second)){
                    if(res.first < ans_c){
                        ans_c = res.first;
                        ans_j = res.second;
                    }else if(res.second < ans_j){
                        ans_c = res.first;
                        ans_j = res.second;
                    }
                }
            }
        }
        c = ans_c;
        j = ans_j;
    }

    return {c, j};
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
