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
    int chr[26];
    for(int i = 0;i<26;i++)
        cin>>chr[i];
    string str;
    cin>>str;
    map<long long, long long> s[26];
    long long curSum = 0;
    long long res = 0;
    for(int i = 0;i<str.length();i++){
        int idx = str[i]-'a';
        int wt = chr[idx];
        if(s[idx].find(curSum) != s[idx].end())
            res += s[idx][curSum];
        curSum += wt;
        if(s[idx].find(curSum) == s[idx].end())
            s[idx][curSum] = 0;
        s[idx][curSum]++;
    }
    cout<<res<<endl;
}
