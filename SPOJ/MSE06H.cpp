/*
    Nimesh Ghelani (nims11)
    BIT
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
int BIT[3000];
int n,m,k;
void update(int idx)
{
	while(idx<=m)
	{
		BIT[idx]++;
		idx+=(idx & -idx);
	}
}
int query(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=BIT[idx];
		idx -= (idx & -idx);
	}
	return ans;
}
vector< pair<int, int> > foo;
int x,y;
int main()
{
    int c = 0;
    in_T
    {
        c++;
        scanf("%d%d%d", &n, &m, &k);
        for(int i=0;i<=m;i++)
            BIT[i] = 0;
        foo.clear();
        for(int i=0;i<k;i++)
        {
            scanf("%d%d", &x, &y);
            foo.push_back(make_pair(x, y));
        }
        sort(foo.begin(), foo.end());
        long long ans = 0;
        for(int i=0;i<foo.size();i++)
        {
            ans += query(m)-query(foo[i].second);
            update(foo[i].second);
        }
        printf("Test case %d: %lld\n", c, ans);
    }
}
