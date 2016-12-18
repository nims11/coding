/*
    Nimesh Ghelani (nims11)
    BIT
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
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
int arr[21000];
int n;
int BIT[31000];
void update(int idx, int val)
{
	while(idx<=n)
	{
		BIT[idx]+=val;
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
int findidx(int val, int start, int end)
{
    if(start == end)
        return start;
    int mid = (start+end)/2;
    int foo = query(mid)-query(start-1);
//    cout<<val<<" "<<start<<" "<<end<<" "<<foo<<endl;
    if(foo >= val)
        return findidx(val, start, mid);

    return findidx(val-foo, mid+1, end);
}
int main()
{
    n = 10;
    for(int i=1;i<=10;i++)
        BIT[i] = 0, arr[i-1] = 0;
    for(int i=1;i<=10;i++)
        update(i, 1);
    in_T
    {
        in_I(n);
        for(int i=1;i<=n;i++)
            BIT[i] = 0, arr[i-1] = 0;
        for(int i=1;i<=n;i++)
            update(i, 1);
        int skip = 2, cur = 1;
        for(int i=0;i<n;i++)
        {
            int idx;
            int foo = query(n)-query(cur-1);
            int bar = skip%(n-i);
            if(bar == 0)
                bar = n-i;
            if(foo < bar)
            {
                idx = findidx(bar-foo, 1, cur-1);
            }else
                idx = findidx(bar, cur, n);

//            for(int j=1;j<=n;j++)
//                cout<<query(j)-query(j-1)<<" ";
//            newline;
            arr[idx-1] = i+1;
            cur = idx;
            update(idx, -1);
            skip++;

        }
        for(int i=0;i<n;i++)
            printf("%d ", arr[i]);
            newline;
    }
}
