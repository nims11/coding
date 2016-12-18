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
char str[1003];
int main()
{
    in_T
    {
        in_S(str);
        int x1[26] = {0}, x2[26] = {0};
        int len = strlen(str);
        for(int i=0;i<len/2;i++)
            x1[str[i]-'a']++;
        for(int i=len/2+(len%2); i<len;i++)
            x2[str[i]-'a']++;
        bool flag = true;
        for(int i=0;i<26;i++)
            if(x1[i] != x2[i])
                flag = false;
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
