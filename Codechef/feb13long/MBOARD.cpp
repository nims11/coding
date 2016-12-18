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
int n,q, tmp1, tmp2;
int col_0[500005], row_0[500005], col_1[500005], row_1[500005];
char tmp[10];
void update(int *BIT, int idx, int n, int val)
{
	while(idx<=n)
	{
		BIT[idx]+=val;
		idx+=(idx & -idx);
	}
}
int query(int *BIT, int idx, int n)
{
	int ans=0;
	while(idx>0)
	{
		ans+=BIT[idx];
		idx -= (idx & -idx);
	}
	return ans;
}
int main()
{
    scanf("%d%d", &n, &q);
    int row[n+1][2], col[n+1][2];
    for(int i=1;i<=n;i++)
        row[i][0] = col[i][0] = 0, row[i][1] = col[i][1] = 1;
    int len = q+2;
    for(int i=0;i<=len;i++)
        col_0[i] = col_1[i] = row_1[i] = row_0[i] = 0;
    update(col_0, 1, len, n);
    update(row_0, 1, len, n);
    int curr = 2;
    while(q--)
    {
        scanf("%s %d", tmp, &tmp1);
        if(tmp[0]=='R')
        {
            if(tmp[3]=='Q')
            {
                if(row[tmp1][0] == 0)
                    printf("%d\n",n-(query(col_1, curr, len) - query(col_1, row[tmp1][1], len)) );
                else
                    printf("%d\n", query(col_0,curr,len) - query(col_0, row[tmp1][1], len));
            }else
            {
                in_I(tmp2);
                if(row[tmp1][0] == 0)
                    update(row_0, row[tmp1][1], len, -1);
                else
                    update(row_1, row[tmp1][1], len, -1);

                row[tmp1][1] = curr;

                if(tmp2 == 0)
                    update(row_0, row[tmp1][1], len, 1);
                else
                    update(row_1, row[tmp1][1], len, 1);

                row[tmp1][0] = tmp2;
                curr++;
            }
        }else
        {
            if(tmp[3]=='Q')
            {
                if(col[tmp1][0] == 0)
                    printf("%d\n",n-(query(row_1,curr,len) - query(row_1,col[tmp1][1],len)) );
                else
                    printf("%d\n", query(row_0, curr, len) - query(row_0, col[tmp1][1],  len));
            }else
            {
                in_I(tmp2);
                if(col[tmp1][0] == 0)
                    update(col_0, col[tmp1][1], len, -1);
                else
                    update(col_1, col[tmp1][1], len, -1);

                col[tmp1][1] = curr;

                if(tmp2 == 0)
                    update(col_0, col[tmp1][1], len, 1);
                else
                    update(col_1, col[tmp1][1], len, 1);

                col[tmp1][0] = tmp2;
                curr++;
            }
        }
    }
}
