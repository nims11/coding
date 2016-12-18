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
int res[53][53];
int find_path(int src, int dest, int n){
    int ret = -1, backlink[n+1];
    queue<int> BFS;BFS.push(src);
    memset(backlink, 0, sizeof(backlink));
    backlink[src] = -1;
    while(!BFS.empty()){
        int x = BFS.front();BFS.pop();
        if(x == dest){
            ret = 1e9;
            while(backlink[x] != -1){
                int pre = backlink[x];
                ret = min(ret, res[pre][x]);
                x = pre;
            }
            x = dest;
            while(backlink[x] != -1){
                int pre = backlink[x];
                res[pre][x] -= ret;
                res[x][pre] += ret;
                x = pre;
            }
            return ret;
        }
        for(int i = 1;i<=n;i++)
            if(i != x && !backlink[i] && res[x][i])
                backlink[i] = x, BFS.push(i);
    }
    return ret;
}
int max_flow(int src, int sink, int n){
    int ret = 0, path_capacity;
    while((path_capacity = find_path(src, sink, n)) != -1)
        ret += path_capacity;
    return ret;
}
int foo(char ch){
    if(ch >= 'a')
        return 27+ch-'a';
    return 1+ch-'A';
}
int main()
{
    int n, c;
    char ch1, ch2;
    in_I(n);
    memset(res, 0, sizeof(res));
    while(n--){
        while((ch1 = getchar()) < 'A');
        while((ch2 = getchar()) < 'A');
        in_I(c);
        res[foo(ch1)][foo(ch2)] += c;
    }
    printf("%d\n", max_flow(1, 26, 52));
}
