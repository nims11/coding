/*
    Nimesh Ghelani (nims11)
    KMP
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
int pi[100][16];
int m,n;
char emot[100][16];
int len[100];
char line[81];
void calc_pref_f(int idx)
{
    pi[idx][0] = 0;
    int k = 0;
    int q;
    for(q = 1; emot[idx][q]; q++)
    {
        while(k>0 && emot[idx][q] != emot[idx][k])
            k = pi[idx][k-1];
        if(emot[idx][k] == emot[idx][q])
            k++;
        pi[idx][q] = k;
    }
    len[idx] = q;
}
struct node{
    int l, r;
}tnode;
vector<node> foo;
void kmp()
{
    for(int idx=0;idx<n;idx++)
    {
        int q = 0;
        for(int i=0; line[i]; i++)
    {
        while(q && emot[idx][q] != line[i])
            q = pi[idx][q-1];
        if(emot[idx][q] == line[i])
            q++;
        if(q == len[idx])
        {
            tnode.l = i+1-len[idx];
            tnode.r = i;
            foo.push_back(tnode);
        }
    }
    }
}
bool cmp(const node &a, const node &b)
{
    return a.r<b.r;
}
int main()
{
    while(1)
    {
        scanf("%d%d\n", &n, &m);
        if(n == 0 && m == 0)return 0;
        for(int i=0;i<n;i++)
        {
            gets(emot[i]);
            calc_pref_f(i);
        }
        int res = 0;
        for(int i=0; i<m; i++)
        {
            gets(line);
            foo.clear();
            kmp();
            sort(foo.begin(), foo.end(), cmp);
            int curr = -1;
            for(int j=0;j<foo.size();j++)
            {
                if(foo[j].l<=curr)
                    continue;
                curr = foo[j].r;
                res++;
            }
        }
        printf("%d\n", res);
    }
}
