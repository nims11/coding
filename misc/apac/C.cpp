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
long long dist[101][101];
const long long  INF = 1e18;
int main(){
    int z = 0;
    in_T{
        z++;
        int n, m;
        vector<int> u, v, cost;
        in_I(n);
        in_I(m);
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                dist[i][j] = INF;
        for(int i = 0;i<n;i++)
            dist[i][i] = 0;
        for(int i = 0;i<m;i++){
            int x, y, c;
            in_I(x);in_I(y);
            in_I(c);
            u.push_back(x);
            v.push_back(y);
            cost.push_back(c);
            dist[x][y] = dist[y][x] = c;
        }
        for(int k = 0;k<n;k++)
            for(int i = 0;i<n;i++)
                for(int j = 0;j<n;j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        cout<<"Case #"<<z<<":"<<endl;
        for(int i = 0;i<u.size();i++){
            bool flag = false;
            for(int j = 0;j<n;j++){
                for(int k = j+1;k<n;k++){
                    long long d1 = cost[i] + dist[u[i]][j] + dist[v[i]][k];
                    long long d2 = cost[i] + dist[v[i]][j] + dist[u[i]][k];
                    if(d1 == dist[j][k] || d2 == dist[j][k]){
                        flag = true;
                    }else{
                    }
                }
            }
            if(!flag)
                cout<<i<<endl;
        }
    }
}
