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
#define in_T int t;for(scanf("%d\n",&t);t--;)
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
int main()
{
    int c = 0;
    in_T
    {
        c++;
        string str;
        getline(cin, str);
        int foo[26] = {0};
        for(int i=0;i<str.size();i++)
        {
            if(isalpha(str[i]))
                foo[tolower(str[i])-'a']++;
        }
        sort(foo, foo+26);
        int ans=0;
        for(int i=25;i>=0;i--)
        {
            ans += foo[i]*(i+1);
        }
        printf("Case #%d: %d\n", c, ans);
    }
}
