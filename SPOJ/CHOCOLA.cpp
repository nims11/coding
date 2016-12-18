/*
given the cost of cuts, the objective of the problem is to minimize the overall cost.
Greedy approach. Sort according to the cost and simulate the cuts and add up the costs.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
struct cost{
    int c;
    bool h;
    friend bool operator<(const struct cost &a,const struct cost &b)
    {
        return a.c>b.c;
    }
};
int main()
{
    cost COSTS[2005];
    int count,m,n,tmp,h_cnt,v_cnt;
    in_T
    {
        count=h_cnt=v_cnt=0;
        in_I(m);in_I(n);
        for(int i=0;i<m-1;i++)
        {
            in_I(tmp);
            COSTS[count].c=tmp;
            COSTS[count++].h=true;
        }
        for(int i=0;i<n-1;i++)
        {
            in_I(tmp);
            COSTS[count].c=tmp;
            COSTS[count++].h=false;
        }
        sort(COSTS,COSTS+count);
        int ans=0;
        for(int i=0;i<count;i++)
        {
//            printf("*%d ",COSTS[i].c);
            if(COSTS[i].h){h_cnt++;ans+=(1+v_cnt)*COSTS[i].c;}
            else {v_cnt++;ans+=(1+h_cnt)*COSTS[i].c;}
//            printf("%d\n",ans);
        }
        printf("%d\n",ans);
    }
}

