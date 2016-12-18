/*
    Nimesh Ghelani (nims11)
    O(n^2)
    for each point, find number longest line it is a part of.
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
pair<int, int> pts[2200];
double slopes[2200];
int main()
{
    in_T
    {
        int n;
        in_I(n);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            in_I(pts[i].first);
            in_I(pts[i].second);
            int foo = 0, cnt=0;
            for(int j=0;j<i;j++)
            {
                if(pts[i].first-pts[j].first == 0)
                    foo++;
                else
                    slopes[cnt++] = double(pts[i].second-pts[j].second)/(pts[i].first-pts[j].first);
            }
            sort(slopes, slopes+cnt);
            ans = max(ans, foo);
            foo = 0;
            int j = 0;
            while(j<cnt)
            {
                int _j = j;
                foo = 0;
                while(_j<cnt && slopes[j]==slopes[_j])
                    _j++, foo++;
                ans = max(ans, foo);
                j = _j;
            }
        }
        printf("%d\n", ans);
    }
}
