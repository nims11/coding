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

#define MAX_N 200000
int sieve[MAX_N+1];
vector<int> primes;
void genPrimes(){
    primes.push_back(2);
    for(int i = 3;i<=MAX_N;i+=2){
        if(sieve[i] == 0){
            primes.push_back(i);
            if(i*1LL*i <= MAX_N)
            for(int j = i*i;j<=MAX_N;j+=i)
                sieve[j] = 1;
        }
    }
}
int grid[1000][1000];
int dp[10001];
int main()
{
    genPrimes();

    int N, K;
    in_I(N);in_I(K);
    for(int i = 1;i<=10000;i++){
        int x = i;
        int idx = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
        int c = 0;
        if(primes[idx] == x){
            dp[x] = -1;
        }else
        while(primes[idx] < 100000){
            if((primes[idx] - x)%K == 0){
                dp[x]  = (primes[idx]-x)/K;
                break;
            }
            idx++;
        }

    }
    for(int i = 0;i<N;i++)for(int j = 0;j<N;j++){
        int x;
        in_I(x);
        grid[i][j] = dp[x];
    }
    pair<int, int> ans;
    int res = 100;
    for(int i = 1;i<N-1;i++){
        for(int j = 1;j<N-1;j++){
            if(grid[i][j] && grid[i-1][j-1] && grid[i+1][j+1] && grid[i-1][j+1] && grid[i+1][j-1]){
                int r = max(grid[i][j], 0)+max(grid[i-1][j-1], 0)+
                    max(grid[i+1][j+1], 0) + max(grid[i-1][j+1], 0)+max(grid[i+1][j-1], 0);
                if(r < res)
                    res = r, ans = make_pair(i, j);
            }
        }
    }
    if(res != 100){
        cout<<"yes"<<endl;
        cout<<res<<endl;
        cout<<ans.first+1<<" "<<ans.second+1<<endl;;
    }else
        cout<<"no"<<endl;
}
