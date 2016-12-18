/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<set>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
using namespace std;
int main()
{
    set <int> f,fof;
    set<int>::iterator it;
    int tmp,n;
    int count=0;
    in_T
    {
        in_I(tmp);
        f.insert(tmp);
        in_I(n);
        while(n--)
        {
            in_I(tmp);
            fof.insert(tmp);
        }
    }
    for(it=fof.begin();it!=fof.end();it++)
        {
            if(f.find(*it)==f.end())count++;
        }
    printf("%d\n",count);
}
