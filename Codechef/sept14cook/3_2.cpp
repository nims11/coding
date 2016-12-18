/*
 *     Nimesh Ghelani (nims11)
 *     */
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
void sieve(){
    for(int i = 2;i<=1000;i++){
        if(tmp[i] == 0){
            primes.push_back(i);
            for(int j = i*i;j<=1000;j+=i)
                tmp[j] = 1;

        }

    }

}
int main()
{
    sieve();
    in_T{
        int N;
        in_I(N);
        map<int, int> prev;
        int prevv[primes.size()];
        for(int i = 0;i<primes.size();i++)
            prevv[i] = -1;
        int ans = -1;
        int prevAns = -1;
        for(int i = 0;i<N;i++){
            int x;
            in_I(x);
            int curAns = 1e9;
            int lt = sqrt(x);
            for(int j = 0;j<primes.size() && primes[j]<=lt;j++){
                if(x%primes[j] == 0){
                    curAns = min(curAns, i-prevv[j]);
                    prevv[j] = i;
                    while(x%primes[j] == 0)
                        x/=primes[j];

                }

            }
            if(x != 1){
                if(prev.find(x) == prev.end())
                    prev[x] = -1;
                curAns = min(curAns, i-prev[x]);
                prev[x] = i;

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

