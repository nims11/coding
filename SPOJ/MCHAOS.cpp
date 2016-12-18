/*
    Nimesh Ghelani (nims11)
    mask + BIT
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
#define in_I(a) scanf("%d\n",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int BIT[100002];
int n;
void update(int idx)
{
	while(idx<=n)
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
struct foo
{
    long long val, rev_val;
    int idx;
};
bool comp1(const foo &a, const foo &b)
{
    return a.val<b.val;
}
bool comp2(const foo &a, const foo &b)
{
    return a.rev_val<b.rev_val;
}
int main()
{
    in_I(n);
    char str[12];
    foo repr[n];
    int j;
    for(int i=0;i<n;i++)
    {
        in_S(str);
        repr[i].val = repr[i].rev_val = 0;
        for(j=0;str[j];j++)
            repr[i].val |= ((long long)(str[j]-'a'+1))<<(45-5*j);
        int len = j;
        for(j--;j>=0;j--)
        {
            repr[i].rev_val |= ((long long)(str[j]-'a'+1))<<(45-5*(len-j-1));
        }
//        cout<<repr[i].val<<" "<<repr[i].rev_val<<endl;
    }
    sort(repr, repr+n,
         comp1
         );
    for(int i=0;i<n;i++)
        repr[i].idx = i+1;
    for(int i=0;i<=n;i++)
        BIT[i] = 0;
    long long ans = 0;
    sort(repr, repr+n, comp2);
    for(int i=0;i<n;i++)
    {
        update(repr[i].idx);
        ans += query(n)-query(repr[i].idx);
    }

    cout<<ans<<endl;
}
