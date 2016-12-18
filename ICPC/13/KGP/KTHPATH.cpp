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
int N;
long long Q;
struct node
{
    set<int> neigh;
    int size;
}nodes[1000001];
int X, Y;
vector<int> ans;
int get_size(int idx, int par)
{
    int ret = 1;
    for(set<int>::iterator it = nodes[idx].neigh.begin(); it != nodes[idx].neigh.end(); it++)
    if(*it != par)
        ret += get_size(*it, idx);
    return ret;
}
void gen(int idx, long long Q, int par = -1)
{
//    cout<<idx<<", "<<Q<<endl;
    if(Q == 0)
        return;
    set<int>::iterator it;
    int curr = 0;
    int prev = 0;
    for(it = nodes[idx].neigh.begin(); it != nodes[idx].neigh.end(); it++)
    {
        if(*it == par)
            continue;
        prev = curr;
        curr += get_size(*it, idx);
        if(curr>=Q-1)
        {
            ans.push_back(*it);
            gen(*it, Q-prev-1, idx);
    return;
        }
    }
}
int main()
{
    in_T
    {
        ans.clear();
        in_I(N);
        in_L(Q);
        for(int i = 1;i<=N;i++)
            nodes[i].neigh.clear();
        for(int i = 0;i<N-1;i++)
        {
            in_I(X);
            in_I(Y);
            nodes[X].neigh.insert(Y);
            nodes[Y].neigh.insert(X);
        }
        long long start = Q/N+bool(Q%N);
        ans.push_back(start);
        gen(start, Q-N*(Q/N-bool(Q%N == 0)));
        for(int i = 0;i<ans.size(); i++)
            printf("%d ", ans[i]);
        newline;
    }
}
