/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int N,  K;
int fav[1010];
int mrks[51];
int field[720721];
int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
vector<int> vec_field;
long long LCM;
vector<int> neigh[1010];
int in[1010];
double sum[1010];
long long getNext(long long x){
    long long rem = x%LCM;
    int idx = lower_bound(BE(vec_field), rem) - vec_field.begin();
    return x/LCM*LCM + vec_field[idx];
}
double dfs(int idx, long long prev){
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i];
        long long cur_next = getNext(prev*2+1);
        sum[idx] = max(sum[idx], (double)cur_next);
        if(in[v] == 1)
            dfs(v, cur_next);
        else
            in[v]--;
    }
    return 0;
}
double solve(){
    for(int i = 0;i<N;i++)
        neigh[i].clear(), in[i] = 0, sum[i] = 0;
    for(int i = 1;i<N;i++){
        if(fav[i] > fav[i-1])
            neigh[i-1].push_back(i), in[i]++;
    }
    for(int i = 0;i<N;i++){
        if(in[i] == 0)
            dfs(i, 0);
    }
    double x = 0;
    for(int i = 0;i<N;i++)
        x += sum[i];
    return x / N;
}
int main()
{
    in_T{
        in_I(N);
        vec_field.clear();
        for(int i = 0;i<N;i++)
            in_I(fav[i]);
        in_I(K);
        for(int i = 0;i<K;i++)
            in_I(mrks[i]);
        LCM = mrks[0];
        for(int i = 1;i<K;i++){
            LCM = LCM*mrks[i]/GCD(LCM, mrks[i]);
        }
        cout<<LCM<<endl;
        assert(LCM <= 720720);
        memset(field, 0, sizeof(field));
        queue<int> BFS;
        BFS.push(0);
        field[0] = 1;
        vec_field.push_back(0);
        while(!BFS.empty()){
            int x = BFS.front();
            BFS.pop();
            for(int i = 0;i<K;i++){
                if(mrks[i] + x <= LCM && field[mrks[i]+x] == 0){
                    field[mrks[i]+x] = 1;
                    vec_field.push_back(mrks[i]+x);
                    BFS.push(mrks[i]+x);
                }
            }
        }
        sort(BE(vec_field));
        printf("%.8lf\n", solve());
    }
}
