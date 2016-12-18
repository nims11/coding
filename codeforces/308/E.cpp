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
long long res[5002];
string str;
long long solve(int st, int end){
    if(end >= (int)str.size() || end < 0)return 1;
    long long res = 1;
    for(int i = st;i<=end;i++)
        if(str[i] == '+')
            return solve(st, i-1)+solve(i+1, end);
    for(int i = st;i<=end;i++)
        if(str[i] != '*')
            res *= str[i]-'0';
    return res;
}
int xxx, yyy;
long long solve2(int st, int end){
    if(end >= (int)str.size() || end < 0)return 1;
    long long res = 1;
    if(st == xxx){
        res = solve(xxx, yyy);
        if(end == yyy)
            return res;
        long long misc = 0;
        for(int i = yyy+1;i<=end;i++){
            if(str[i] == '+'){
                misc = solve(i+1, end);
                break;
            }
        }
        for(int i = yyy+1;i<=end;i++){
            if(str[i] == '*')
                res *= str[i+1]-'0';
            if(str[i] == '+'){
                res += misc;
                break;
            }
        }
        return res;
    }
    long long suff = solve2(xxx, end);
    for(int i = xxx-1;i>=0;i--){
        if(str[i] == '*')
            suff *= str[i-1]-'0';
        else if(str[i] == '+')
            return suff+solve(0, i-1);
    }
    return suff;
}
int main()
{
    cin>>str;
    vector<int> foo;
    int cur = 0;
    foo.push_back(0);
    for(int i = 0;i<str.size();i++){
        if(str[i] == '*'){
            foo.push_back(i+1);
        }
    }
    foo.push_back(str.size()+1);
    long long result = solve(0, str.length()-1);
    // cout<<result<<endl;
    // for(int i = 0;i<foo.size();i++)
        // cout<<foo[i]<<" ";
    // cout<<endl;
    for(int i = 0;i<foo.size();i++){
        for(int j = i+1;j<foo.size();j++){
            xxx = foo[i];
            yyy = foo[j]-2;
            result = max(result, solve2(0, str.size()-1));
            // cout<<i<<" "<<j<<" "<<result<<endl;
        }
    }
    cout<<result<<endl;
}
