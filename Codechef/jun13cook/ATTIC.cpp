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
char str[1000003];
int main()
{
    in_T
    {
        in_S(str);
        int ans = 0;
        int cur = 0;
        int L = 0;
        for(int i=0;str[i];i++)
        {
            if(str[i] == '#')
            {
                if(cur && cur>L)
                {
                    L = cur;
                    ans++;
                    cur = 0;
                }
                cur = 0;
            }
            else
                cur++;
        }
        printf("%d\n", ans);
    }
}
