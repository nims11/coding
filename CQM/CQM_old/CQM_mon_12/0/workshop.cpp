/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<sstream>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
string str1,str2,order;
int dp[203][203];
int getans(int index,int curr_sess)
{
    if(curr_sess==order.length())return 1;
    int ans=0;
    for(int i=index;i<str1.length();i++)
    if(str1[i]==order[curr_sess])
    ans+=getans(i+1,curr_sess+1);

    for(int i=index;i<str2.length();i++)
    if(str2[i]==order[curr_sess])
    ans+=getans(i+1,curr_sess+1);

    return ans;
}
int main()
{
    string sss;
    while(getline(cin,sss))
    {
        stringstream ss(sss);
        ss>>order>>str1>>str2;
//        for(int i=0;i<str1.length();i++)
//        {
//            dp[i][order.length()]=1;
//            for(int j=0;j<order.length();j++)
//        {
//            dp[i][j]=-1;
//            dp[str1.length()][j]=0;
//        }
//        }
        dp[str1.length()][order.length()]=1;
        for(int i=0;i<order.length();i++)
        order[i]='a'+order[i]-'A';
        int ans=getans(0,0);
        if(ans!=0)
        cout<<"Saurabh can do classes in "<<getans(0,0)<<" ways\n";
        else
        cout<<"Saurabh cant take the classes in the desired sequence.\n";
    }
}
