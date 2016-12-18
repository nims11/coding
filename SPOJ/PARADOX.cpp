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
int n, x;
char str[10];
pair<int, int> foo[101];
pair<int, int> bar[101];
int par[101];
int curr_par;
bool baz(int idx)
{
    par[idx] = curr_par;
    if(foo[idx].first == -1)
        foo[idx].first = 0, foo[idx].second = 1;
    int x = bar[idx].first, y = bar[idx].second;
    int a1 = (y^(!foo[idx].first)),
        a2 = (y^(!foo[idx].second));
    if(foo[x].first == -1)
    {
        foo[x].first = a1;
        foo[x].second = a2;
        return baz(x);
    }else
    {
        if(par[x] == curr_par)
            return (foo[x].first == a1 && foo[x].second == a2);
        else
            return baz(x);
    }
}
int main()
{
    while(in_I(n) != EOF)
    {
        if(n == 0)
            return 0;
        for(int i = 1; i<=n; i++)
        {
            foo[i].first = foo[i].second = -1;
            in_I(x);
            in_S(str);
            if(str[0] == 't')
                bar[i] = make_pair(x, 1);
            else
                bar[i] = make_pair(x, 0);
        }
        bool flag = false;
        for(int i = 1; i<=n; i++)
        {
            if(foo[i].first == -1)
            {
                curr_par = i;
                if(!baz(i))
                {
                    flag = true;
                    break;
                }
            }
//            cout<<foo[i].first<<" "<<foo[i].second<<endl;
        }
        printf(flag?"PARADOX\n":"NOT PARADOX\n");
    }
}
