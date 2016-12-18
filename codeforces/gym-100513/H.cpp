#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

int v[500010];
vector<pair<int, pair<int, int>>> triangles;
#define MAXN 500010
struct LogCache {
    int LOG2[MAXN];
    LogCache();
};
LogCache::LogCache(){
    int curr = 2;
    LOG2[1] = 0;
    for(int i = 2; i<MAXN;i++){
        if(i == curr){
            curr <<= 1;
            LOG2[i] = LOG2[i-1] + 1;
        }else
            LOG2[i] = LOG2[i-1];
    }
}

struct RMQ{
    int n;
    pair<int, int> aux[MAXN][22];
    pair<int, int> aux_2[MAXN][22];
    static LogCache logCache;
    void init(int n, const int *arr);
    pair<int, int> query(int x, int y);
    pair<int, int> query2(int x, int y);
}rmq;
LogCache RMQ::logCache;
void RMQ::init(int N, const int *arr){
    this->n = N;
    for(int i=1;i<=N;i++){
        aux[i][0] = {arr[i], i};
        aux_2[i][0] = {arr[i], -i};
    }
    for(int j=1; (1<<j)<=N+1; j++)
        for(int i=1;i+(1<<j)<=n+1;i++){
            aux[i][j] = min(aux[i][j-1], aux[i+(1<<(j-1))][j-1]);
            aux_2[i][j] = min(aux_2[i][j-1], aux_2[i+(1<<(j-1))][j-1]);
        }
}
pair<int, int> RMQ::query(int x, int y){
    int k = logCache.LOG2[y-x+1];
    return min(aux[x][k], aux[y-(1<<k)+1][k]);
}

pair<int, int> RMQ::query2(int x, int y){
    int k = logCache.LOG2[y-x+1];
    return min(aux_2[x][k], aux_2[y-(1<<k)+1][k]);
}
int n;
int bar[3];
void triangulate(int x, int y){
    if( y-x == 1 || (x == n && y == 1)) return;
    pair<int, int> smallest_node;
    if( x < y ){
        if(v[y] < v[x])
            smallest_node = rmq.query(x+1, y-1);
        else smallest_node = rmq.query2(x+1, y-1);
    }
    else{
        if(v[y] < v[x]){
            pair<int, int> cand1 = x < n?rmq.query(x+1, n):make_pair(int(1e9), -1);
            pair<int, int> cand2 = y>1?rmq.query(1, y-1):make_pair(int(1e9), -1);
            if(cand1.second == -1)
                smallest_node = cand2;
            else if(cand2.second == -1)
                smallest_node = cand1;
            else if(cand1.first != cand2.first){
                smallest_node = min(cand1, cand2);
            }else
                smallest_node = cand1;
        }else{
            pair<int, int> cand1 = x < n?rmq.query2(x+1, n):make_pair(int(1e9), 1);
            pair<int, int> cand2 = y>1?rmq.query2(1, y-1):make_pair(int(1e9), 1);
            if(cand1.second == 1)
                smallest_node = cand2;
            else if(cand2.second == 1)
                smallest_node = cand1;
            else if(cand1.first != cand2.first){
                smallest_node = min(cand1, cand2);
            }else
                smallest_node = cand2;
        }
    }
    if(smallest_node.second < 0)
        smallest_node.second = -smallest_node.second;

    bar[0] = x;
    bar[1] = y;
    bar[2] = smallest_node.second;
    for(int i = 0;i<3;i++){
        for(int j = i+1;j<3;j++)
            if(v[bar[i]] > v[bar[j]])swap(bar[i], bar[j]);
    }
    triangles.push_back({bar[0], {bar[1], bar[2]}});
    triangulate(x, smallest_node.second);
    triangulate(smallest_node.second, y);
}
int main(){
    in_I(n);
    vector<pair<int, int>> foo(2);
    for(int i = 0;i<2;i++)
        foo[i] = {1e9, -1};
    for(int i = 1;i<=n;i++){
        in_I(v[i]);
        if(foo[1].first > v[i]){
            foo[1] = {v[i], i};
        }
        if(foo[1] < foo[0])swap(foo[0], foo[1]);
    }
    rmq.init(n, v);
    triangulate(foo[0].second, foo[1].second);
    triangulate(foo[1].second, foo[0].second);
    sort(triangles.begin(), triangles.end(), [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) -> bool
            {
                return make_pair(v[a.first], make_pair(v[a.second.first], v[a.second.second]))
                < make_pair(v[b.first], make_pair(v[b.second.first], v[b.second.second]));
            }
        );
    for(auto ans: triangles){
        bar[0] = ans.first;
        bar[1] = ans.second.first;
        bar[2] = ans.second.second;
        for(int i = 0;i<3;i++){
            for(int j = i+1;j<3;j++)
                if(v[bar[i]] > v[bar[j]])swap(bar[i], bar[j]);
        }
        printf("%d %d %d\n",  bar[0], bar[1], bar[2]);
    }
}
