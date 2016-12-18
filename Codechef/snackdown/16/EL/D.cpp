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
long long arr[101];
pair<long long, long long> states[7];
long long nextVal;
int getState(long long x){
    for(int i = 0;i<7;i++){
        if(states[i].first <= x && x <= states[i].second)
            return i;
    }
    return -1;
}
void updateStates(long long x){
    while(1){
        long long maxEnd = 2*nextVal - 1;
        int state = -1;
        for(int i = 0;i<7;i++){
            if(states[i].first == -1){
                state = i;
                break;
            }
            long long state_begin = states[i].first*2;
            long long state_end = (states[i].second+1)*6-1;
            if(state_begin <= nextVal && nextVal <= state_end){
                maxEnd = min(maxEnd, state_end);
            }else if(nextVal < state_begin){
                maxEnd = min(maxEnd, state_begin-1);
                state = i;
                break;
            }else if(nextVal > state_end){
                state = i;
                break;
            }
        }
        // cerr<<state<<" "<<nextVal<<" "<<maxEnd<<endl;
        states[state].first = nextVal;
        states[state].second = maxEnd;
        nextVal = maxEnd+1;
        if(x <= maxEnd)
            return;
    }
}
int main(){
    in_T{
        states[0] = {0,0};
        for(int i = 1;i<7;i++)
            states[i] = {-1, -1};
        nextVal = 1;
        int n;
        in_I(n);
        vector<int> grundy;
        for(int i = 0;i<n;i++){
            in_L(arr[i]);
        }
        sort(arr, arr+n);
        for(int i = 0;i<n;i++){
            long long x = arr[i];
            int state = getState(x);
            if(state == -1){
                updateStates(x);
                state = getState(x);
            }
            grundy.push_back(state);
        }
        int xorsum = 0;
        for(int x: grundy)
            xorsum ^= x;
        printf(xorsum?"Henry\n":"Derek\n");
    }
}
