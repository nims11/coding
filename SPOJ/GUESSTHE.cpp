/*
 * find the LCM of all the multiples, then perform a contradictory check for all numbers not a multiple of the number.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
long long GCD(long long a,long long b)
{
    long long temp;
    while(b>0)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}
long long LCM(long long a,long long b)
{
    return a*(b/GCD(a,b));
}
int main()
{
    string str;
    while(cin>>str)
    {
        if(str[0]=='*')break;
        vector<int>foo;
        long long ans=1;
        if(str[0]=='N')
        {
            ans=-1;
        }else
        {
            for(int i=1;i<str.length();i++)
            {
                if(str[i]=='Y')
                ans=LCM(i+1,ans);
                else
                foo.push_back(i+1);
            }
            for(int i=0;i<foo.size();i++)
            if(ans%foo[i]==0)
            {
                ans=-1;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
