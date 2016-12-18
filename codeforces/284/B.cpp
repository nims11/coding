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
int prev[205];
int n, m;
int res[205][205];
int max_flow_dinic(int src, int sink, int n){
    int ret = 0;
    int prev[n+1];
    while(1){
        queue<int> BFS;
        memset(prev, 0, sizeof(prev));
        prev[src] = -1;
        BFS.push(src);
        while(!BFS.empty() && !prev[sink]){
            int curr = BFS.front();
            cout<<curr<<endl;
            BFS.pop();
            for(int i = 1;i<=n;i++)
                if(!prev[i] && res[curr][i] )
                    prev[i] = curr, BFS.push(i);
        }
        if(!prev[sink])
            break;
        for(int i = 1;i<=n; i++){
            if(res[i][sink] && prev[i]){
                int inc = res[i][sink];
                for(int u = prev[i], v = i; u>=0; inc = min(inc, res[u][v]), v = u, u = prev[u]);
                for(int u = i, v = sink; u>=0; res[u][v]-=inc, res[v][u]+=inc, v = u, u = prev[u]);
                ret += inc;
            }
        }
    }
    return ret;
}
int find_path(int src, int dest, int n){
    int ret = -1, backlink[n+1];
    queue<int> BFS;BFS.push(src);
    memset(backlink, 0, sizeof(backlink));
    backlink[src] = -1;
    while(!BFS.empty()){
        int x = BFS.front();BFS.pop();
        if(x == dest){
            ret = 1000;
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

int sieve[31625];
vector<int> primes;
int arr[101];
int pp[101][2];
int main()
{
    primes.push_back(2);
    for(int i = 3;i<31625;i+=2){
        if(sieve[i] == 0){
            primes.push_back(i);
            for(int j = i*i;j<31625;j+=i)
                sieve[j] = 1;
        }
    }
    in_I(n);in_I(m);
    for(int i = 1;i<=n;i++){
        in_I(arr[i]);
    }
    for(int i = 1;i<=m;i++){
        in_I(pp[i][0]);
        in_I(pp[i][1]);
    }
    int src = 2*n+1, sink = 2*n+2;
    int ans = 0;
    for(int i = 0;i<primes.size();i++){
        for(int j=1;j<=2*n+2;j++)
            for(int k = 1;k<=2*n+2;k++)
                res[j][k] = 0;
        for(int j = 1;j<=m;j++)
            res[pp[j][0]][n+pp[j][1]] = res[pp[j][1]][pp[j][0]+n] = 100;
        for(int j=1;j<=n;j++)
            while(arr[j]%primes[i] == 0)
                arr[j]/=primes[i], 
                res[src][j] = (++res[n+j][sink]);

        ans += max_flow(src, sink, 2*n+2)/2;
    }

    for(int i = 1;i<=n;i++){
        if(arr[i] == 1)continue;
        for(int j=1;j<=2*n+2;j++)
            for(int k = 1;k<=2*n+2;k++)
                res[j][k] = 0;
        for(int j = 1;j<=m;j++)
            res[pp[j][0]][n+pp[j][1]] = res[pp[j][1]][pp[j][0]+n] = 100;

        int x = arr[i];
        for(int j=1;j<=n;j++)
            while(arr[j]%x == 0)
                arr[j]/=x, 
                res[src][j] = (++res[n+j][sink]);
        ans += max_flow(src, sink, 2*n+2)/2;
    }
    printf("%d\n", ans);
}
