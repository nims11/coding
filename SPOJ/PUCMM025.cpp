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
string str;
int is_div[10];
int main()
{
    is_div[0] = 0;
    is_div[1] = 1;
    while(cin>>str)
    {
        int sum = 0;
        is_div[2] = ((str[str.length()-1]-'0')%2 == 0);
        for(int i=0;i<str.length();i++)
            sum += str[i]-'0';
        is_div[3] = (sum%3==0);
        int foo = 0;
        for(int i=(int)(str.length())-3;i<(int)str.length();i++)
        {
            foo = foo*10+(i<0?0:(str[i]-'0'));
        }
        is_div[4] = (foo%4==0);
        is_div[5] = (str[str.length()-1] =='0' || str[str.length()-1] == '5');
        is_div[6] = is_div[2]*is_div[3];
        int cur = str[0]-'0';
        for(int i=1;i<str.length();i++)
        {
            cur = (cur*3+str[i]-'0')%7;
        }
        is_div[7] = (cur==0);
        is_div[8] = (foo%8==0);
        is_div[9] = (sum%9==0);
        int ans = 0;
        for(int i=0;i<str.length();i++)
            ans += is_div[str[i]-'0'];
        cout<<ans<<endl;
    }
}
