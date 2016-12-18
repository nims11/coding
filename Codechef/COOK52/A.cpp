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
char str[100010];
int main()
{
    in_T{
        in_S(str);
        int f = 0;
        int cur = 0;
        for(int i = 0;str[i];i++){
            if(str[i] == '(')
                cur++;
            else
                cur--;
            f = max(f, cur);
        }
        for(int i = 0;i<f;i++)
            printf("(");
for(int i = 0;i<f;i++)
            printf(")");
newline;

    }
}
