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
vector<int> primes;
const int limit = 1000;
int tmp[1003];
vector<int> factors[1000001];
void sieve(){
    for(int i = 2;i<=1000;i++){
        if(tmp[i] == 0){
            primes.push_back(i);
            for(int j = i*i;j<=1000;j+=i)
                tmp[j] = 1;
            for(int j = i;j<=1000000;j+=i){
                factors[j].push_back(i);
            }
        }
    }
}
int main()
{
    sieve();
    cout<<"X"<<endl;
    for(int i = 2;i<=1000000;i++)
        if(factors[i].size() == 0)
            factors[i].push_back(i);
    in_T{
        int N;
        in_I(N);
        map<int, int> prev;
        int ans = -1;
        int prevAns = -1;
        for(int i = 0;i<N;i++){
            int x;
            in_I(x);
            int curAns = 1e9;
            if(x == 1)
                curAns = i+1;
            for(int j = 0;j<factors[x].size();j++){
                    if(prev.find(factors[x][j]) == prev.end())
                        prev[factors[x][j]] = -1;
                    curAns = min(curAns, i-prev[factors[x][j]]);
                    prev[factors[x][j]] = i;
                    while(x%factors[x][j] == 0)
                        x/=factors[x][j];
            }
            if(prevAns == -1){
                prevAns = 1;
                continue;
            }
            int curStart = i-curAns+1, prevStart = i-prevAns;
            if(curStart <= prevStart)
                curAns = prevAns+1;
            prevAns = curAns;
            
            ans = max(ans, curAns);
        }
        printf("%d\n", ans<2?-1:ans);
    }
}
