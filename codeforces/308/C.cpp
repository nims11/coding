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
int w, m, n;
long long pow_w[101];
bool getans(int x, int st, int end){
    // cout<<x<<" "<<st<<" "<<end<<endl;
    if(x == 0)return 1;
    if(end < st)return 0;
    int pre = upper_bound(pow_w+st, pow_w+end+1, x) - pow_w;
    pre--;
    if(pre != end && getans(pow_w[pre+1]-x, st, pre))
        return 1;
    if(getans(x-pow_w[pre], st, pre-1))
        return 1;
    return 0;
}
int main()
{
    cin>>w>>m;
    pow_w[0] = 1;
    for(int i = 1;i<=100;i++){
        if(pow_w[i-1] >= m){
            n = i-1;
            break;
        }
        pow_w[i] = pow_w[i-1]*w;
        n = i;
    }
    if(getans(m, 0, n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
