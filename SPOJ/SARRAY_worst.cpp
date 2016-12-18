/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
//#include<cstring>
#include<cstdlib>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
int ranks[200];
int strcmp(const char *a, const char *b)
{
    int x = 0;
    while(a[x] == b[x])
    {
        if(a[x] == 0)
            return 0;
        x++;
    };
    return -(ranks[a[x]]-ranks[b[x]]);
}
int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
}
int main()
{
    ranks[0] = -1;
    int cnt = 0;
    for(char ch = '0';ch<='9';ch++)
        ranks[ch] = cnt++;
    for(char ch = 'A';ch<='Z';ch++)
        ranks[ch] = cnt++;
    for(char ch = 'a';ch<='z';ch++)
        ranks[ch] = cnt++;
        char str[100001];
        in_S(str);
        char *suffix[100001];
        int len = 0;
        for(;str[len];len++)
        suffix[len]=str+len;
        qsort(suffix,len,sizeof(char*),cstring_cmp);
        for(int i=0;i<len;i++)
            printf("%d\n", str+len-suffix[i]);
}

