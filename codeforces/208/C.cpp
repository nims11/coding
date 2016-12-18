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
set<pair<int, int> > foo;
set<pair<int, int> >::iterator it;
int n;
struct node
{
    int x;
    bool pop[3];
    bool push[3];
    node(){pop[0] = pop[1] = pop[2] = push[0] = push[1] = push[2] = false;}
}res[100001];
int x;
int main()
{
    in_I(n);
    int cur_ptr = 0;
    for(int i = 0; i< n;i++)
    {
        in_I(x);
        res[i].x = x;
        if(x == 0)
        {
            int cnt = 0;
            while(cnt < 3 && !foo.empty())
            {
                it = foo.end();
                --it;
                res[it->second].push[cnt] = true;
                res[i].pop[cnt] = true;
                cnt++;
                foo.erase(it);
            }
            foo.clear();
        }else
        {
            foo.insert(make_pair(x, i));
        }
    }
    for(int i = 0;i<n;i++)
    {
        if(res[i].x == 0)
        {
            int x = res[i].pop[0]+res[i].pop[1]+res[i].pop[2];
            printf("%d", x);
            if(x)
                printf(" ");
            if(res[i].pop[0])
            {
                printf("popStack");
                x--;
                if(x)
                    printf(" ");
            }
            if(res[i].pop[1])
            {
                printf("popQueue");
                x--;
                if(x)
                    printf(" ");
            }
            if(res[i].pop[2])
            {
                printf("popFront");
                x--;
                if(x)
                    printf(" ");
            }
            newline;
        }else
        {
            if(res[i].push[0])
                printf("pushStack\n");
            else if(res[i].push[1])
                printf("pushQueue\n");
            else if(res[i].push[2])
                printf("pushFront\n");
            else
                printf("pushBack\n");
        }
    }
}
