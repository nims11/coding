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
int K;
char str[1000003];
int len;
int pi[1000003];
void gen()
{
    pi[1] = 0;
    int k = 0;
    for(int q=1;q<len;q++)
    {
        while(k>0 && str[q] != str[k])
            k = pi[k];
        if(str[q] == str[k])
            k++;
        pi[q+1] = k;
    }
}
int main()
{
    while(1)
    {
        in_I(K);in_S(str);
        if(K == -1)
            return 0;
        len = strlen(str);
        gen();

        int ans = (K-pi[len])/(len-pi[len]);
        printf("%d\n", max(0, ans));
    }
}
