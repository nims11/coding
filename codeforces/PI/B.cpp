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
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
bool arr[1000010];
int main()
{
    int n;
    cin>>n;
    int res = 0;
    int cur = 0;
    for(int i = 0;i<n;i++){
        char c; int x;
        cin>>c>>x;
        if(c == '-'){
            if(!arr[x])
                res++;
            else
                cur--, arr[x] = !arr[x];
        }
        else{
            cur++;
            arr[x] = true;
        }
        res = max(res, cur);
    }
    cout<<res<<endl;
}
