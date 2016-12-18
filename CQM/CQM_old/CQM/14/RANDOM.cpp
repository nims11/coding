
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
int main()
{
    in_T
    {
        int n,k,a;
        in_I(n);
        in_I(k);
        map<int, int> foo;
        map<int, int>::iterator it;
        long long x = 0;
        for(int i=0;i<n;i++)
        {
            in_I(a);
            it = foo.find(a);
            if(it == foo.end())
                foo[a] = 1;
            else
                it->second++;
            it = foo.find(a-k);
            if(it != foo.end())
                x += it->second;
            it = foo.find(a+k);
            if(it != foo.end())
                x += it->second;
        }
        if(x>n/2)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
