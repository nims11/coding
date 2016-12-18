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
int histo[1001];
int m,n;
stack<int> stk;
int getans()
{
    int ret = 0;
    for(int i=0;i<n;i++)
    {
        if(stk.size() == 0 || histo[stk.top()] <= histo[i])
            stk.push(i);
        else
        {
            while(stk.size() && histo[stk.top()]>=histo[i])
            {
                int x = stk.top();
                stk.pop();
                ret = max(ret, histo[x]*(i-1-(stk.size()>0?stk.top():-1)));
            }
            stk.push(i);
        }
    }
    while(stk.size())
    {
        int x = stk.top();
        stk.pop();
        ret = max(ret, histo[x]*(n-1-(stk.size()>0?stk.top():-1)));
    }
    return ret;
}
int main()
{
    in_T
    {
       in_I(m);
       in_I(n);
       int ans = 0;
       char tmp[4];
       for(int i=0;i<m;i++)
        histo[i] = 0;
       for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                in_S(tmp);
                if(tmp[0] == 'R')
                    histo[j] = 0;
                else
                    histo[j]++;
            }
            ans = max(ans, getans());
        }
        printf("%d\n", ans*3);
    }
}
