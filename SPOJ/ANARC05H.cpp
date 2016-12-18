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
string str;
int getans(int idx, int pre)
{
    if(idx == str.length())
        return 1;

    int i = idx;
    int cur = 0;
    int ret = 0;
    while(i<str.length())
    {
        cur += str[i++]-'0';
        if(cur>=pre)
        {
            ret+=getans(i, cur);
        }
    }
    return ret;
}
int main()
{
    int c =0;
    while(cin>>str)
    {
        c++;
        if(str[0] == 'b')
            return 0;
        printf("%d. %d\n", c, getans(0, -1));
    }
}
