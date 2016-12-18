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
class NODE{
    public:
    int a,b,c;
    friend istream& operator>>(istream& is, NODE &Q)
    {
        is>>Q.a>>Q.b>>Q.c;
        return is;
    }
    NODE& operator=(const NODE &Q)
    {
        a = Q.a;
        b = Q.b;
        c = Q.c;
    }
};
int main()
{
    int c=0;
    while(1)
    {
        c++;
        int n;
        in_I(n);
        if(n==0)return 0;
        NODE pre,curr;
        cin>>pre>>curr;
        pre.c += pre.b;
        curr.a += pre.b;
        curr.b += min(curr.a,min(pre.b,pre.c));
        curr.c += min(pre.b,min(curr.b,pre.c));
        pre = curr;
        for(int i=2;i<n;i++)
        {
            cin>>curr;
            curr.a += min(pre.a,pre.b);
            curr.b += min(curr.a,min(pre.a,min(pre.b,pre.c)));
            curr.c += min(pre.b,min(pre.c,curr.b));
            pre = curr;
        }
        cout<<c<<". "<<curr.b<<endl;
    }

}
