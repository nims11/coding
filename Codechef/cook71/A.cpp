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
    in_T{
        int N;
        in_I(N);
        vector<int> arr;
        for(int i = 0;i<N;i++){
            int x;
            in_I(x);
            arr.push_back(x);
        }
        sort(BE(arr));
        int candi1 = -1, candi2 = -1;
        int curCount = 0;
        int curVal = -1;
        for(int i = arr.size()-1;i>=0;i--){
            if(arr[i] != curVal){
                curVal = arr[i];
                curCount = 0;
            }
            curCount++;
            if(curCount == 2){
                curCount = 0;
                if(candi1 == -1){
                    candi1 = curVal;
                }else if(candi2 == -1){
                    candi2 = curVal;
                    break;
                }
            }
        }
        if(candi2 == -1){
            cout<<"-1"<<endl;
        }else
            cout<<candi1*candi2<<endl;
    }
}
