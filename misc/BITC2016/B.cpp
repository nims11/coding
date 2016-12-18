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
int arr[100010];
int death[100010];
int foo[100010];
vector<pair<int, int>> ranges;
int aux[100002][23];
int LOG2[100002];
int inf = 1e9;
int RMQ(int x, int y)
{
    int k = LOG2[y-x+1];
    return max(aux[x][k], aux[y-(1<<k)+1][k]);
}
int main(){
    int z = 0;
    int curr = 2;
    LOG2[1] = 0;
    for(int i = 2; i<=100001;i++)
    {
        if(i == curr)
        {
            curr <<= 1;
            LOG2[i] = LOG2[i-1] + 1;
        }else
            LOG2[i] = LOG2[i-1];
    }

   int N, M;
   in_I(N);
   for(int i = 1;i<=N;i++)
       death[i] = inf;
   in_I(M);
   for(int i = 0;i<N;i++){
       in_I(arr[i+1]);
   }
   for(int i = 0;i<M;i++){
       int x, y;
       in_I(x);in_I(y);
       ranges.push_back({x,y});
   }
   int Q, Q1;
   int time = 0;
   in_I(Q);
   Q1 = Q;
   while(Q--){
       int x;
       time++;
       in_I(x);
       if(arr[x] > 0){
            arr[x]--;
            if(arr[x] == 0){
                death[x] = time;
            }
       }
   }
   for(int i=1;i<=N;i++)
       aux[i][0] = death[i];
   for(int j=1; (1<<j)<=N+1; j++)
       for(int i=1;i+(1<<j)<=N+1;i++)
           aux[i][j] = max(aux[i][j-1], aux[i+(1<<(j-1))][j-1]);
   vector<int> resArr;
   for(auto x: ranges){
       int xx = RMQ(x.first, x.second);
       if(xx != inf)
           resArr.push_back(xx);
   }
   sort(BE(resArr));
   int cur = 0;
   int ptr = 0;
   for(int i = 1;i<=Q1;i++){
       while(ptr < resArr.size() && resArr[ptr] <= i){
        cur++;
        ptr++;
       }
       printf("%d\n", cur);
   }
}
