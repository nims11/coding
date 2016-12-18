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

const int MAX_N = 500;
const int MAX_N_bit = 500/64+1;
int N;
int N_new;
struct Matrix{
    int m[MAX_N][MAX_N];
    unsigned long long rows[MAX_N][MAX_N_bit];
    unsigned long long cols[MAX_N][MAX_N_bit];
}adj;

void fillRowsCol(Matrix &X){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(j%64 == 0)
                X.rows[i][j/64] = X.cols[i][j/64] = 0;
            if(X.m[i][j])
                X.rows[i][j/64] |= 1LL<<(j%64);
            if(X.m[j][i])
                X.cols[i][j/64] |= 1LL<<(j%64);
        }
    }
}
void matmul(Matrix &A, Matrix &B, Matrix &res){
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++){
            res.m[i][j] = 0;
            for(int k = 0;k<N_new;k++)
                if(A.rows[i][k]&B.cols[j][k]){
                    res.m[i][j] = 1;
                    break;
                }
        }
    fillRowsCol(res);
}

struct Query{
    int k, x, idx;
};

Matrix tmpMain, curMain;
vector<Matrix> mats;
map<unsigned int, map<string, int>> s;
int ans[500];
int nxt[500][31];
void solve(){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(adj.m[i][j] == 1){
                nxt[i][0] = j;
                break;
            }
        }
    }
    for(int z = 1;z<=30;z++){
        for(int i = 0;i<N;i++){
            nxt[i][z] = nxt[nxt[i][z-1]][z-1];
        }
    }
    int M;
    in_I(M);
    while(M--){
        int k, x;
        in_I(k);in_I(x);
        int cur = x-1;
        int idx = 30;
        while(idx >= 0 && (1<<idx) > k)idx--;
        while(idx >= 0){
            if((1<<idx) <= k){
                k -= (1<<idx);
                cur = nxt[cur][idx];
            }
            idx--;
        }
        printf("1\n%d \n", cur+1);
    }
}
int main(){
    static Matrix *tmp = &tmpMain;
    static Matrix *cur = &curMain;
    static int curpow = 0;
    in_I(N);
    bool lol = true;
    N_new = N/64 + (N%64 > 0);
    for(int i = 0; i < N;i++){
        int lolx = 0;
        for(int j = 0;j<N;j++){
            in_I(adj.m[i][j]);
            lolx += adj.m[i][j];
        }
        if(lolx != 1)
            lol = false;
    }

    if(lol){
        solve();
        return 0 ;
    }
    fillRowsCol(adj);

    int M;
    in_I(M);
    for(int i = 0; i < N;i++)
        cur->m[i][i] = 1;
    fillRowsCol(*cur);
    int idx = 0;
    int offset = 0;
    while(true){
        string val;
        unsigned int hash = 1;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                val.push_back(cur->m[i][j]?'1':'0');
                hash = hash*mod + val.back();
            }
        }
        if(s.find(hash) != s.end()){
            if(s[hash].find(val) != s[hash].end()){
                offset = s[hash][val];
                break;
            }
        }
        s[hash][val] = idx;
        mats.push_back(*cur);
        matmul(*cur, adj, *tmp);
        swap(cur, tmp);
        idx++;
    }
    while(M--){
        int k,x;
        in_I(k);
        in_I(x);
        int cnt = 0;
        int xxx = k % idx;
        if(k < offset) xxx = k;
        else xxx = offset + ((k-offset) % (idx-offset));
        for(int i = 0;i<N;i++)
            if(mats[xxx].m[x-1][i]) ans[cnt++] = i+1;
        printf("%d\n", cnt);
        if(cnt == 0)
            printf("-1");
        else for(int i = 0;i < cnt;i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
}
