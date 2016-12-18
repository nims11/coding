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
int a[100001];
int b[100001];

int main()
{
    string str;
    cin>>str;
    for(int i=1;i<str.length();i++)
    {
        a[i] = a[i-1] + (str[i] == str[i-1]);
    }
    in_T
    {
        int x,y;
        cin>>x>>y;
        int res = a[y-1]-a[x-1];
        cout<<res<<endl;
    }
}
