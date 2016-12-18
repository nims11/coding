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
char str[100004];
int k;
int main()
{
    in_T
    {
        in_S(str);
        in_I(k);
        int len = strlen(str);
        int i;
        int curr[10] = {0};
        int last = 10000;
        string x;
        for(i=0;i<len && k;i++)
        {
            curr[str[i]-'0']++;
            if(str[i]<=last)
            {
                last = str[i];
                continue;
            }
            curr[str[i]-'0']--;
            for(int j=0;k && j<str[i]-'0';j++)
            {
                int X = min(k, curr[j]);
                k -= X;
                curr[j] -= X;
                if(k == 0)
                {
                    x.push_back(str[i]);
                    curr[str[i]-'0']--;
                    break;
                }
            }
            curr[str[i]-'0']++;
        }
        if(k != 0)
        {
            for(int j=len-1;k && j>=i;j--)
            {
                str[j] = 0;
                k--;
            }
            if(k && x.size())
                x="", k--;
            if(k)
            {
                for(int j=0;j<10 && k;j++)
                {
                    int x = min(k, curr[j]);
                    k -= x;
                    curr[j] -= x;
                }
            }
        }
        for(int i=9;i>=0;i--)
        {
            while(curr[i]--)
                putchar('0'+i);
        }
        if(x.size())
            putchar(x[0]);
        for(;str[i];i++)
            putchar(str[i]);
        newline;
    }
}
