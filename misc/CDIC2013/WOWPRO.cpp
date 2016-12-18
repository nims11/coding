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
char str[20000];
int is_vow(char c)
{
    int x = 1;
    if(isupper(c))
    {
        c = tolower(c);
        x = 2;
    }
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return x;
    return 0;
}
int main()
{
    in_T
    {
        int doo[26];
        for(int i=0;i<26;i++)
            doo[i] = 0;
        in_S(str);
        for(int i=0;str[i];i++)
        {
            doo[tolower(str[i])-'a'] += is_vow(str[i]);
        }
        long long ans = 1;
        for(int i=0;i<26;i++)
            if(doo[i])ans *= doo[i];
        printf("%lld\n",  ans);
    }
}
