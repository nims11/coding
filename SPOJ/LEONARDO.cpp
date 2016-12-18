/*
    Nimesh Ghelani (nims11)
    let f(x) be the substitution function. We are given f(f(x))
    Imagine edge X->Y if f(f(X)) = Y
    All the disjoint graphs are cycles. Problem is to determine If we can assign this node values in such a way to all the edges such that the whole system is consistent.
    Only 2 rules are valid
        - odd sized cycles can have edge values from the nodes in the same cycle. (Assign node values to the edge opposite to that node).
        - two equal even sized cycles, when considered together, can make each other consistent.
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
char str[30];
vector<int> cycles;
int visited[26];
int dfs(int idx)
{
    if(visited[idx])
        return 0;
    visited[idx] = 1;
    return 1+dfs(str[idx]-'A');
}
bool isValid()
{
    cycles.clear();
    for(int i=0;i<26;i++)
        visited[i] = 0;
    for(int i=0;i<26;i++)
    {
        if(!visited[i])
            cycles.push_back(dfs(i));
    }
    sort(cycles.begin(), cycles.end());
    for(int i=0;i<cycles.size();i++)
    {
        if(cycles[i]%2)
            continue;
        if(i==cycles.size()-1)
            return false;
        if(cycles[i]!=cycles[i+1])
            return false;
        i++;
    }
    return true;
}
int main()
{
    in_T
    {
        in_S(str);
        if(isValid())
            printf("Yes\n");
        else
            printf("No\n");
    }
}
