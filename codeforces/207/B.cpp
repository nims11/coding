/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
string str1, str2;
long long dp[1000001][26];
bool solved[1000001];
int ex[1000001];
int gen(int n)
{
    if(solved[n])
        return n;
//    cout<<n<<endl;
    int nxt = (n+str1.length())%str2.length();
    solved[n] = true;
    ex[n] = gen(nxt);
    for(int i = 0;i<26;i++)
    {
        dp[n][i] = dp[nxt][i];
    }
    dp[n][str2[n]-'a']++;
}
long long GCD(long long a,long long b)
{
    while(b^=a^=b^=a%=b);
    return a;
}

int main()
{
    long long n,m;
    in_L(n);
    in_L(m);
    cin>>str1>>str2;
    int l1 = str1.length(), l2 = str2.length();
    long long ans = 0;
    for(int i = 0;i<str1.length();i++)
    {
        gen(i%str2.length());
        ans += dp[i%str2.length()][str1[i]-'a'];
        cout<<i<<" "<<dp[ex[i%str2.length()]][0]<<endl;
    }
    ans = (str1.length()*1LL*str2.length())/GCD(str1.length(), str2.length())-ans;

    ans *= GCD(n, m);
    cout<<ans<<endl;
}
