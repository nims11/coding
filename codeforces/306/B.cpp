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
int main()
{
    int n, l, r, x;
    cin>>n>>l>>r>>x;
    int c[n];
    for(int i = 0;i<n;i++)
        cin>>c[i];
    int res = 0;
    for(int i = 1;i<(1<<n);i++){
        int mini = 1e9, maxi = -1, sum = 0;
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                sum += c[j];
                mini = min(mini, c[j]);
                maxi = max(maxi, c[j]);
            }
        }
        if(maxi - mini >= x && sum >= l && sum <= r)
            res++;
    }
    cout<<res<<endl;
}
