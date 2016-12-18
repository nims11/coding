/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    std::vector<int> diff;int n,val,g=0,pre;
    in_I(n);
    in_I(pre);
    for(int i=1;i<n;i++)
    {
        in_I(val);
        diff.push_back(val-pre);
        if(g==0)g=val-pre;
        else
        g=gcd(val-pre,g);
        pre=val;
    }
    int ans=0;
    for(int i=0;i<diff.size();i++)
    ans+=diff[i]/g-1;
    printf("%d\n",ans);
}
