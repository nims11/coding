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
#include<cstring>
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
    char str1[510], str2[510];
    while(1)
    {
        scanf("%s%s",str1,str2);
//        cout<<str1<<str2<<"s"<<endl;
        if(str1[0]=='*')return 0;
        int ans=0;
        int len=strlen(str1);
        for(int i=0;i<len;i++)
        {
            bool flag = true;
            while(str1[i] && str1[i]!=str2[i])
            {flag=false;i++;}
//            cout<<int(str1[i])<<endl;
            ans+=!flag;
        }
        P_I(ans);
        newline;
    }
}
