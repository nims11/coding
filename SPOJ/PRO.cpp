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
    int n, k, tmp;
    in_I(n);
    multiset<int> foo;
    long long unsigned ans = 0;
    multiset<int>::iterator start, end;
    for(int i=0;i<n;i++)
    {
        in_I(k);
        while(k--)
        {
            in_I(tmp);
            foo.insert(tmp);
        }
        start = foo.begin(), end = foo.end();end--;
        ans += *end - *start;
        foo.erase(start);
        foo.erase(end);
    }
    cout<<ans<<endl;
}
