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
        int n, m;
        in_I(n);
        pair<int, int> a1[n+1];
        int x;
        a1[0] = make_pair(0, 0);
        for(int i = 1; i<=n; i++)
        {
            in_I(x);
            if(!x) a1[i].first = 1, a1[i].second = 0;
            else    a1[i].second= 1, a1[i].first = 0;
            a1[i].first += a1[i-1].first;
            a1[i].second += a1[i-1].second;
        }
        in_I(m);
        pair<int, int> a2[m+1];
        a2[0] = make_pair(0, 0);
        for(int i = 1; i<=m; i++)
        {
            in_I(x);
            if(!x) a2[i].first = 1, a2[i].second = 0;
            else    a2[i].second= 1, a2[i].first = 0;
            a2[i].first += a2[i-1].first;
            a2[i].second += a2[i-1].second;
        }
        bool flag = true;
        for(int i = m; i<=n; i++)
        {

            if(a2[m].first == a1[i].first-a1[i-m].first && a2[m].second == a1[i].second-a1[i-m].second)
            {
                printf("%d\n", i-m);
                flag = false;
                break;
            }
        }
        if(flag)
            printf("-1\n");
    }
}
