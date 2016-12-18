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
int ans[100001];
int cur_cnt;
void rec(int start, int end)
{
//    cout<<start<<" "<<end<<endl;
    if(start>end)
        return;
    if(end-start<=100)
    {
        for(int i=start;i<=end;i++)
        {
            int j =0;
            if(flag[arr[i]])continue;
            for(; j<cur_cnt; j++)
            {
                if(!((arr[i]&1)^((ans[j])&1)))
                    if(flag[(arr[i]+ans[j])/2])
                        break;
            }

            if(j == cur_cnt)
            {
                for(int j=0;j<cur_cnt;j++)
                {
                    if(!((arr[i]&1)^((ans[j])&1)))
                        flag[(arr[i]+ans[j])/2] = true;
                }
                ans[cur_cnt++] = arr[i], flag[arr[i]] = true;
            }
        }
        return;
    }
    int lt1 = arr[start] + (arr[end]-arr[start])/3;
    int lt2 = arr[start] + 2*(arr[end]-arr[start])/3;
    int idx1 = 0;
    int idx2 = end;
    while(arr[idx1]<lt1)idx1++;
    while(arr[idx2]>=lt2)idx2--;
    idx2++;
//    cout<<idx1<<" - "<<idx2<<endl;
//    int x;cin>>x;
//    int cnt = cur_cnt;
    rec(start, idx1-1);
//    int cnt1 = cur_cnt;
    rec(idx2, end);
//    int cnt2 = cur_cnt;
//    for(int i=cnt;i<cnt1;i++)
//    {
//        for(int j=lt2;j<cnt2;j++)
//            if(!((ans[i]&1)^((ans[j])&1)))
//                flag[(ans[i]+ans[j])/2] = true;
//    }
    rec(idx1, idx2-1);
}
int main()
{
    in_I(n);
    int l = 0;
    for(int i=0;i<n;i++)
    {
        in_I(arr[i]);
        l = arr[i];
    }
    rec(0, n-1);
    printf("%d\n", cur_cnt);
    for(int i=0;i<cur_cnt;i++)
        printf("%d ", ans[i]);
    newline;
}
