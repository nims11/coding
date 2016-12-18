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
int main()
{
    in_T
    {
        int n;
        in_I(n);
        int arr[n], arr2[n], vis[n];
        int ans = 0;
        map<int, int> pos;
        for(int i = 0; i<n; i++)
        {
            in_I(arr[i]);
            arr2[i] = arr[i];
            vis[i] = 0;
            pos[arr[i]] = i;
        }
        sort(arr2, arr2+n);
        for(int i = 0; i<n; i++)
        {
            if(vis[i])continue;
            int c = arr[i];
            int x = lower_bound(arr2, arr2+n, c) - arr2;
            ans++;
            int st = i;
            for(int j = x+1; j<n; j++)
            {
                int y = pos[arr2[j]];
                if(y>st)
                {
                    st = y;
                    vis[st] = 1;
                }else
                break;
            }
            st = i;
            for(int j = x-1; j>=0; j--)
            {
                int y = pos[arr2[j]];
                if(y>st)
                {
                    st = y;
                    vis[st] = 1;
                }
            }
        }


        printf("%d\n", ans);
    }
}
