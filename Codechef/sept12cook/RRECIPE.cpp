/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
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
int main()
{
    int mod = 10000009;
    in_T
    {
        string str;
        cin>>str;
        long long ans=1;
        for(int i=0;i<str.length()/2;i++)
        {
            if(str[i]=='?')
            {
                if(str[str.length()-1-i]=='?')
                {
                    ans = (ans*26)%mod;
                }
            }else
            {
                if(str[i]!=str[str.length()-1-i] && str[str.length()-1-i]!='?')
                {
                    ans=0;
                    break;
                }
            }
        }
        if(ans)
        {
            if(str.length()%2)
            {
                if(str[str.length()/2]=='?')
                ans = (ans*26)%mod;
            }
        }
        cout<<ans<<endl;
    }
}
