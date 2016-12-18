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
int getres(int v, int n, int mod=0, int cur=0)
{
    if(cur == n)
    {
        return (mod==0);
    }
    int ret = 0;
    for(int i=0;i<v;i++)
    {
        ret += getres(v,n, (mod+v+i)%v, cur+1);
    }
    return ret;
}
int main()
{
    for(int v=1;v<=10;v++)
    {
        for(int n=1;n<=10;n++)
        {
            cout<<v<<" "<<n<<" = "<<getres(v,n)<<endl;
        }
    }
}
