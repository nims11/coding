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
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
bool check(int *foo){
    set<int> x;
    for(int i = 0;i<26;i++)
        if(foo[i])x.insert(foo[i]);
    return (x.size() == 1);
}
int main()
{
    string str;
    cin>>str;
    int foo[26] = {0};
    for(int i = 0;i<str.length();i++)
        foo[str[i]-'a']++;
    bool flag = check(foo);
    for(int i = 0;i<26;i++){
        if(foo[i]){
            foo[i]--;
            flag |= check(foo);
            foo[i]++;
        }
    }
    cout<<(flag?"YES":"NO")<<endl;
}
