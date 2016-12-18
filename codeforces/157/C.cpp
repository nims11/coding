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
    string str;
    cin>>str;
    string q;
    bool foo = true;
    for(int i=0;i<str.length();i++)
    {
        if( foo && str[i]=='0')
        {
            foo = false;
        }else
        q.push_back(str[i]);
    }
    int i =0;
    if(foo)
        i=1;
    for(;q[i]=='0' && i<q.length();i++);
    if(i==q.length())
        cout<<'0'<<endl;
    for(;i<q.length();i++)
        cout<<q[i];
    cout<<endl;
}
