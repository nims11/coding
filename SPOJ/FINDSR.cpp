/*
    Nimesh Ghelani (nims11)
    KMP
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
int pi[100003];
char P[100003];
void compute_pi()
{
    pi[0] = 0;
    int k = 0;
    int i;
    for(i=1;P[i];i++)
    {
        while(k>0 && P[k] != P[i])
            k = pi[k-1];
        if(P[k] == P[i])
            k++;
        pi[i] = k;
    }

    if(i%(i-pi[i-1]) == 0)
        printf("%d\n", i/(i-pi[i-1]));
    else
        printf("1\n");
}

int main()
{
    while(1)
    {
        in_S(P);
        if(P[0] == '*')
            return 0;
        compute_pi();
    }
}
