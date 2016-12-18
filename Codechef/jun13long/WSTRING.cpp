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
char str[10002];
int foo[26];
int bar[26];
int arr[10000];
int all_max[10000];
int all_max_rev[10000];
int main()
{
    in_T
    {
        in_S(str);
        memset(foo, 0, 26*sizeof(int));
        memset(bar, 0, 26*sizeof(int));
        int cnt = 0;
        int i;
        for(i=0;;i++)
        {
            if(str[i] == '#' || !str[i])
            {
                arr[cnt] = *max_element(foo, foo+26);
                all_max[cnt++] = *max_element(bar, bar+26);
                if(!str[i])
                    break;
                memset(foo, 0, 26*sizeof(int));
            }else
            {
                foo[str[i]-'a']++;
                bar[str[i]-'a']++;
            }
        }
        int cnt2 = cnt;
        memset(bar, 0, 26*sizeof(int));
        for(--i;;i--)
        {
            if(str[i] == '#' || i == -1)
            {
                all_max_rev[--cnt2] = *max_element(bar, bar+26);
                if(i == -1)
                    break;
            }else
                bar[str[i]-'a']++;
        }
        int ans = 0;
        if(cnt>=4)
        {
            int curr;
            int zeroes;
            for(int i=3;i<cnt;i++)
            {
                curr = all_max[i-3] + arr[i-2] + arr[i-1] + all_max_rev[i];
                zeroes = (all_max[i-3]==0) + (arr[i-2]==0) + (arr[i-1]==0) + (all_max_rev[i]==0);
                if(!zeroes)
                    ans = max(ans, curr+3);
            }
        }
        printf("%d\n", ans);
    }
}
