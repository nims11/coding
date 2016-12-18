/*
    Nimesh Ghelani (nims11)
    Find the maximum angular separation among the consecutive landmarks.
    To do this, insert all the angles in a multiset and iterate over it and take care of the first and last angles.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<string>
#include<cmath>
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
int main()
{
    in_T
    {
        int n;
        in_I(n);
        char str[100];double dd;
        double ans=0;
        multiset<double> foo;
        multiset<double>::iterator it;
        for(int i=0;i<n;i++)
        {
//            in_S(str);
            in_F(dd);
            foo.insert(dd);
        }
        double start;
        it=foo.begin();double pre=start=*it;
        it++;
        for(;it!=foo.end();it++)
        {
            ans=max(ans,*it - pre);
            pre=*it;
        }
        ans=max(ans,360 - pre + start);
        ans=4320 - ans*12;
        cout<<ans<<endl;
    }
}
