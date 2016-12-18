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
vector<pair<int, int> > circ;
int main()
{
    int n;
    in_I(n);

    bool flag = true;
    int pre;
    in_I(pre);
    for(int i = 2;i<=n;i++)
    {
        int x;
        in_I(x);
//        cout<<i<<endl;
        for(int j = 0;j<circ.size(); j++)
        {
            if(x > circ[j].first && x < circ[j].second && (pre < circ[j].first || pre > circ[j].second))
            {
                flag = false;
                i = n+1;
                break;
            }else if (pre > circ[j].first && pre < circ[j].second && (x < circ[j].first || x > circ[j].second))
            {
                flag = false;
                i = n+1;
                break;
            }
        }
        circ.push_back(make_pair(min(pre, x), max(pre, x)));
        pre = x;
    }
    cout<<(!flag?"yes":"no")<<endl;
}
