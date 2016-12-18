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
    in_T
    {
        string foo;
        cin>>foo;
        int bar = 0;
        if(foo.find(".")!=string::npos)
        {
            int x = foo.find(".");
            x++;
            int a = 1000;
            while(x<foo.length())
            {
                bar+=(foo[x]-'0')*a;
                a/=10;
                x++;
            }
        }
        int qaz = bar;
        int cnt = 1;
        while(bar)
        {
            cnt++;
            bar+=qaz;
            bar = bar%10000;
//            cout<<bar<<endl;
        }
        cout<<cnt<<endl;
    }
}
