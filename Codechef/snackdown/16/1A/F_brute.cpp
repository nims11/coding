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
int N,m;
long long x, y;
int main(){
    in_T{ 
        in_I(N);
        in_I(m);in_L(x);
        in_L(y);
        for(int i = 1;i<=N;i++)
            in_I(arr[i]);
        vector<int> *tmp = new vector<int>();
        for(int i = 1;i<=N;i++)
            tmp->push_back(arr[i]);
        long long ans = 0;
        for(int i = 0;i<m;i++){
            vector<int> *tmp2 = new vector<int>();
            tmp2->push_back((*tmp)[0]);
            for(int j = 1;j<tmp->size();j++){
                tmp2->push_back(ADD((*tmp)[j], (*tmp)[j-1]));
                tmp2->push_back((*tmp)[j]);
            }
            swap(tmp, tmp2);
            delete tmp2;
        }
        for(int i = x-1;i<=y-1;i++)
            ans = ADD(ans, (*tmp)[i]);
        printf("%lld\n", ans);
    }
}
