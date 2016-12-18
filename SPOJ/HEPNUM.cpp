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
#include<cstring>
using namespace std;
char str1[100002], str2[100002];
int main()
{
    while(1)
    {
        scanf("%s%s", str1, str2);
        if(str1[0] == '*')return 0;
        int len1 = strlen(str1), len2 = strlen(str2);
        int curr1 = 0, curr2 = 0;
        while(curr1<len1 && str1[curr1]=='0')curr1++;
        while(curr2<len2 && str2[curr2]=='0')curr2++;
        if(len1-curr1>len2-curr2)printf(">\n");
        else if(len1-curr1<len2-curr2)printf("<\n");
        else
        {
            while(str1[curr1]==str2[curr2] && curr1<len1 && curr2<len2)curr1++, curr2++;
            if(str1[curr1]==str2[curr2])printf("=\n");
            else if(str1[curr1]<str2[curr2])printf("<\n");
            else printf(">\n");
        }
    }
}
