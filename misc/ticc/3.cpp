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
#include<cassert>
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
multiset<pair<int, int> > evts;
int main()
{
    int n, k;
    in_I(n);
    in_I(k);
    for(int i = 0;i<n;i++){
        int x;
        in_I(x);
        evts.insert(make_pair(x, 1));
    }
    for(int i = 0;i<k;i++){
        int x, y;
        in_I(x);
        in_I(y);
        evts.insert(make_pair(x, 0));
        evts.insert(make_pair(y, 2));
    }
    int cur = 0;
    int res = 0;
    for(multiset<pair<int, int> >::iterator it = evts.begin(); it!=evts.end(); it++){
        if(it->second == 0)
            cur++;
        else if(it->second == 2)
            cur--;
        else
            res += (cur != 0);
    }
    cout<<res<<endl;
}
