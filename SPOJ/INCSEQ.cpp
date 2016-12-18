/*
    Nimesh Ghelani (nims11)
    BIT[][k] represents BIT for length k
    for each element in an array,
    update_BIT([order(arr[i])][k]) = query[order(arr[i])-1, k-1]
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
int BITS[10005][55] = {{0}};
int arr[10005], arr_copy[10005];
int cnt;
int new_id[100004];
int mod = 5000000;
void update(int idx, int k, int val)
{
	while(idx<=cnt)
	{
		BITS[idx][k]+=val;
		BITS[idx][k]%=mod;
		idx+=(idx & -idx);
	}
}
int query(int idx, int k)
{
	int ans=0;
	while(idx>0)
	{
		ans+=BITS[idx][k];
		ans%=mod;
		idx -= (idx & -idx);
	}
	return ans;
}
int main()
{
    int n,k;
    in_I(n);
    in_I(k);
    for(int i=0;i<n;i++)
        in_I(arr[i]);
    for(int i=0;i<n;i++)
        arr_copy[i] = arr[i];
    sort(arr_copy, arr_copy+n);
    cnt = 1;
    for(int i=0;i<n;i++)
        new_id[arr_copy[i]] = cnt++;
    for(int i=0;i<n;i++)
    {
        //if(arr[i]!=0)
        {
            update(new_id[arr[i]], 1, 1);
            for(int j=2;j<=k;j++)
            {
                int x = query(new_id[arr[i]]-1, j-1);
                update(new_id[arr[i]], j, x);
            }
        }
    }
    printf("%d\n", query(cnt, k));
}
