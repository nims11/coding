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
int n,a,b;
int main()
{
    in_T
    {
        map<int,int> foo;
        map<int,int>::iterator it;
        int ans=0;
        in_I(n);
        while(n--)
        {
            scanf("%d%d",&a,&b);
            foo[a]=b;
            for(it=foo.begin();it!=foo.end();it++)
            {
                if(it->first < a)
                {
                    if(it->second >= b)ans++;
                }else if(it->first > a)
                {
                    if(it->second <= b)ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
