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
char s[50002];
int pos[50002][26];
int last;
char ans[50002], maxi[50002];
int l_ans, l_maxi;
int odd_ans, odd_maxi;
void chk()
{
    ans[l_ans] = 0;
    if(l_ans*2 - odd_ans > l_maxi*2 - odd_maxi)
        strcpy(maxi, ans), odd_maxi = odd_ans, l_maxi = l_ans;

    if(l_ans*2 - odd_ans >= 100)
    {
        int l = l_ans*2 - odd_ans;
        if(l>100 && odd_ans)
            odd_ans = 0, l_ans--, l--;
        while(l>100)
        {
            l_ans--;
            l = l_ans*2 - odd_ans;
        }
        for(int i=0;i<l_ans-1;i++)
            printf("%c", ans[i]);
        printf("%c", ans[l_ans-1]);
        if(!odd_ans)
            printf("%c", ans[l_ans-1]);
        for(int i=int(l_ans)-2;i>=0;i--)
            printf("%c", ans[i]);
        newline;
        exit(0);
    }
}
void getans(int st, int end)
{
    if(st > end)
    {
        chk();
        return;
    }
    int pre = -1;
    for(int i = st; i<=end; i++)
    {
        int nxt = pos[end][s[i]-'a'];
        if(nxt <= pre)
            continue;
        pre = nxt;
        ans[l_ans++] = s[i];
        if(nxt == i)
            odd_ans = 1;
        getans(i+1, nxt-1);
        if(nxt == i)
            odd_ans = 0;
        l_ans--;
    }
}
int main()
{
    in_S(s+1);
    int i, len;
    for(i = 1; s[i]; i++)
    {
        pos[i][s[i]-'a'] = i;
    }
    len = i-1;
    for(int i = 1; i <= len; i++)
    {
        for(int j=0;j<26;j++)
        {
            if(pos[i][j] == 0)
                pos[i][j] = pos[i-1][j];
        }
    }
    getans(1, len);
    for(int i=0;i<l_maxi-1;i++)
            printf("%c", maxi[i]);
        printf("%c", maxi[l_maxi-1]);
        if(!odd_maxi)
            printf("%c", maxi[l_maxi-1]);
        for(int i=int(l_maxi)-2;i>=0;i--)
            printf("%c", maxi[i]);
    newline;

}
