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
int k[3];
char str[100];
int type[100];
char tstr[3][100];
int tcnt[3];
int main()
{
    while(1)
    {
        scanf("%d%d%d", &k[0], &k[1], &k[2]);
        if(k[0] == 0) return 0;
        in_S(str);
        tcnt[0] = tcnt[1] = tcnt[2] = 0;
        for(int i=0;str[i];i++)
        {
            if(str[i]>='a' && str[i]<='i')
                type[i] = 0, tstr[0][tcnt[0]++] = str[i];
            else if(str[i]>'i' && str[i]<='r')
                type[i] = 1, tstr[1][tcnt[1]++] = str[i];
            else
                type[i] = 2, tstr[2][tcnt[2]++] = str[i];
        }
        k[0] %= tcnt[0];
        k[1] %= tcnt[1];
        k[2] %= tcnt[2];
        int curr[3];
        curr[0] = tcnt[0]-k[0];
        curr[1] = tcnt[1]-k[1];
        curr[2] = tcnt[2]-k[2];
        for(int i=0;str[i];i++)
        {
            printf("%c", tstr[type[i]][curr[type[i]]]);
            curr[type[i]] = (curr[type[i]]+1)%tcnt[type[i]];
        }
        newline;
    }
}
