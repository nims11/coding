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
bool foo(string &str, int st)
{
    for(int i=st;i<str.length() && str[i-1] == '+';i+=2)
    {
        if(str[i]!='0')
            return true;
    }
    return false;
}
bool bar(string &str, int st)
{
    for(int i=st;i>=0 && str[i+1] == '+';i-=2)
    {
        if(str[i]!='0')
            return true;
    }
    return false;
}
unsigned long long getmax(string str)
{
    int len = str.length()/2 + 1;
    unsigned long long dp[len][len];
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
        dp[i][j] = 0;
    for(int i=0;i<len;i++)
        dp[i][i] = str[i<<1] - '0';

    for(int l = 1;l<len;l++)
    {
        for(int i=0;i<len-l;i++)
        {
            int j = i+l;
            for(int k=i;k<j;k++)
            {
                if(str[2*k+1] == '+')
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
                else
                    dp[i][j] = max(dp[i][j], dp[i][k]*dp[k+1][j]);
            }
        }
    }
    return dp[0][len-1];
}

unsigned long long getmin(string str)
{
    int len = str.length()/2 + 1;
    unsigned long long dp[len][len];
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
        dp[i][j] = -1;
    for(int i=0;i<len;i++)
        dp[i][i] = str[i<<1] - '0';

    for(int l = 1;l<len;l++)
    {
        for(int i=0;i<len-l;i++)
        {
            int j = i+l;
            for(int k=i;k<j;k++)
            {
                if(str[2*k+1] == '+')
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                else
                    dp[i][j] = min(dp[i][j], dp[i][k]*dp[k+1][j]);
            }
        }
    }
    return dp[0][len-1];
}
//unsigned long long getmin(string str)
//{
//    int st = 0, end = str.length()-1;
//    for(int i=0;i<=end;i+=2)
//    {
//        if(str[i] == '0')
//        {
//            if(i!=0)
//            {
//                if(str[i-1] == '*')
//                    st = i;
//            }
//            if(i!=str.length()-1)
//            {
//                if(str[i+1] == '*')
//                {
//                    end = i;
//                    break;
//                }
//            }
//        }
//    }
//    vector<unsigned long long> res;
//    unsigned long long cur = str[st]-'0';
//    for(int i=st+2;i<=end;i+=2)
//    {
//        if(str[i-1] == '*')
//        {
//            cur *= str[i]-'0';
//        }else
//        {
//            res.push_back(cur);
////            cout<<cur<<endl;
//            cur = str[i]-'0';
//        }
//    }
//    res.push_back(cur);
////    cout<<cur<<endl;
//    unsigned long long ress = 0;
//    for(int i=0;i<res.size();i++)
//    ress += res[i];
//    return ress;
//}
int main()
{
    in_T
    {
        string str;
        cin>>str;
        cout<<getmax(str)<<" "<<getmin(str)<<endl;
    }
}
