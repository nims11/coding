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

int main(){
    int z = 0;
    in_T{
        int N;
        in_I(N);
        vector<pair<int, int> > ladders;
        for(int i = 0;i<N;i++){
            int x, h;
            in_I(x);
            in_I(h);
            ladders.push_back({x, h});
        }
        sort(ladders.begin(), ladders.end());
        stack<int> stk;
        long long ans = 0;
        vector<int> sets[N];
        int cntSet = 0;
        int revMap[N];
        for(int i = 0;i<ladders.size();i++){
            int h = ladders[i].second;
            int x = ladders[i].first;
            revMap[i] = -1;
            if(stk.empty() || ladders[stk.top()].second > ladders[i].second){
                stk.push(i);
                revMap[i] = cntSet;
                sets[cntSet].push_back(x);
                cntSet++;
            }
            else{
                while(!stk.empty() && ladders[stk.top()].second < ladders[i].second){
                    stk.pop();
                }
                int prevSet = -1;
                if(!stk.empty() && ladders[stk.top()].second == ladders[i].second){
                    int prev = stk.top();
                    prevSet = revMap[prev];
                }
                if(prevSet == -1)
                    prevSet = cntSet++;
                revMap[i] = prevSet;
                sets[prevSet].push_back(x);
                stk.push(i);
            }
        }
        for(int i = 0;i<cntSet;i++){
            long long sum = 0, sqrSum = 0;
            for(int j = 0;j<sets[i].size();j++){
                // if(z == 4)
                //     cout<<sets[i][j]<<" ";
                sum = ADD(sum, sets[i][j]);
                sqrSum += MUL(sets[i][j],sets[i][j]);
            }
            // if(z == 4){
            //     cout<<endl;
            //     // cout<<sum<<" "<<sqrSum<<endl;
            // }
            sum *= sum;
            long long tmp =MUL(sets[i].size(),sqrSum);
            tmp = (tmp-sum)%mod;
            if(tmp<0)
                tmp += mod;
            ans = ADD(ans, tmp);
        }
        cout<<"Case #"<<(++z)<<": "<<ans<<endl;
    }
}
