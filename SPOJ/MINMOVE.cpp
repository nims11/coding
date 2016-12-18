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
char str[100002];
int main()
{
    in_S(str);
    int len = strlen(str);
    int x = 0, y = 1;
    while(y<len)
    {
        int tmp = 0;
        while(tmp<len && str[(x+tmp)%len] == str[(y+tmp)%len])tmp++;

        if(str[(x+tmp)%len] <= str[(y+tmp)%len])
            y = y+tmp+1;
        else
        {
            x = y;
            y = y+1;
        }
    }
    printf("%d\n", x);
}
