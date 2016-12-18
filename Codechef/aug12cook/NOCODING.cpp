/*
    Nimesh Ghelani (nims11)
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
int main()
{
    in_T
    {
        string str;
        cin>>str;
        int ans=1;
        bool flag=false;
        int curr = str[0]-'a';
        for(int i=0;i<str.length();i++)
        {
//            cout<<char('a'+curr)<<" "<<str[i]<<endl;
            ans += str[i]-'a'>=curr?str[i]-'a'-curr:25-curr+str[i]-'a'+1;
            ans++;
            curr = str[i]-'a';
//            cout<<ans<<endl;
        }
        if(ans>11*str.length())cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
