//GQ
/*
 * reduce the problem as:
 * find the maximum sum by selecting one value from each column such that the bags the three values are related to are distinct.
 * Can be solved by using queue and optimizing the "level"
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
struct foo
{
    int i,value;
    friend bool operator<(const foo &a,const foo &b)
    {
        return a.value>b.value;
    }
};
struct bar
{
    int c,s,b,lvl;
}tmp;
foo c[5100],s[5100],b[5100];
int n;
void getans()
{
    queue<bar> QUEUE;
    tmp.c=tmp.s=tmp.b=tmp.lvl=0;
    QUEUE.push(tmp);
    int ans=0;int g=-1;
    bar sss;
    while(!QUEUE.empty())
    {
        tmp=QUEUE.front();QUEUE.pop();
        if(tmp.lvl>g && g!=-1)break;
        if(c[tmp.c].i!=s[tmp.s].i && s[tmp.s].i!=b[tmp.b].i && b[tmp.b].i!=c[tmp.c].i)
        {
            g=tmp.lvl;
            int k=c[tmp.c].value+s[tmp.s].value+b[tmp.b].value;
            if(k>ans)
            {
                ans=k;
                sss=tmp;
            }
        }else
        {
            tmp.lvl++;
            tmp.c++;if(tmp.c<n)QUEUE.push(tmp);
            tmp.c--;tmp.b++;if(tmp.b<n)QUEUE.push(tmp);
            tmp.b--;tmp.s++;if(tmp.s<n)QUEUE.push(tmp);
        }
    }
    printf("%d\n%d\n%d\n",c[sss.c].i,s[sss.s].i,b[sss.b].i);
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
    {
        in_I(c[i].value);
        in_I(s[i].value);
        in_I(b[i].value);
        c[i].i=i;
        s[i].i=i;
        b[i].i=i;
    }
    sort(c,c+n);sort(s,s+n);sort(b,b+n);
    getans();
}
