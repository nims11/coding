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
int n;
int arr[100000];
int flag[100001];
int ans[3][100001];
int cur_cnt;
int *res;
int res_cnt = 0;
int do_normal(int start, int idx)
{
    int f = -1;
    ans[idx][(cur_cnt=0)] = arr[start];
    cur_cnt++;
    for(int i=start+1; i<n; i++)
    {
        int j =0;
        for(; j<cur_cnt; j++)
        {
            if(!((arr[i]&1)^((ans[idx][j])&1)))
                if(flag[(arr[i]+ans[idx][j])/2])
                {
                    if(f == -1)
                        f = i;
                    break;
                }
        }
        if(j == cur_cnt)
            ans[idx][cur_cnt++] = arr[i], flag[arr[i]] = true;
    }
    if(cur_cnt>res_cnt)
    {
        res_cnt = cur_cnt;
        res = ans[idx];
    }
    return f;
}
int main()
{
    in_I(n);
    int l = 0;
    for(int i=0;i<n;i++)
    {
        in_I(arr[i]);
        l = max(l, arr[i]);
    }
    sort(arr, arr+n);
    int f = do_normal(0, 0);
    memset(flag, 0, 100000*sizeof(int));
    f = do_normal(f, 1);

    memset(flag, 0, 100000*sizeof(int));
    ans[2][(cur_cnt=0)] = arr[0];
    cur_cnt++;
    int i;
    int st = -1, end;
    for(i=1;i<n;i++)
    {
        int j =0;
        for(; j<cur_cnt; j++)
        {
            if(!((arr[i]&1)^((ans[2][j])&1)))
                if(flag[(arr[i]+ans[2][j])/2])
                    break;
        }

        if(j == cur_cnt)
            ans[2][cur_cnt++] = arr[i], flag[arr[i]] = true;

        if(arr[i+1]>=l/3 && st == -1)
        {
            st = i+1;
            while(i<n && arr[i]<=2*l/3)
            i++;
        }
        end = i;
    }
    for(int i=0;i<cur_cnt;i++)
    {
        for(int j=i+1;j<cur_cnt;j++)
            if(!((ans[2][i]&1)^((ans[2][j])&1)))
        {
            flag[(ans[2][i]+ans[2][j])/2] = flag[(ans[2][i]+ans[2][j])/2]!=1?2:1;
        }
    }
    for(int i=st;i<=end;i++)
    {
        int j =0;
        if(flag[arr[i]])continue;
        for(; j<cur_cnt; j++)
        {
            if(!((arr[i]&1)^((ans[2][j])&1)))
                if(flag[(arr[i]+ans[2][j])/2] == 1)
                    break;
        }

        if(j == cur_cnt)
            ans[2][cur_cnt++] = arr[i], flag[arr[i]] = true;
    }
    if(cur_cnt>res_cnt)
    {
        res_cnt = cur_cnt;
        res = ans[2];
    }

    sort(res, res+res_cnt);
    printf("%d\n", res_cnt);
    for(int i=0;i<res_cnt;i++)
        printf("%d ", res[i]);
    newline;
}
