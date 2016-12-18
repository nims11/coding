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
    int z = 0;
    int t;
    cin>>t;
    while(t--){
        z++;
        int D;
        cin>>D;
        int P[D];
        int maxi = 0;
        for(int i = 0;i<D;i++){
            cin>>P[i];
            maxi = max(maxi, P[i]);
        }
        int res = 1e9;
        for(int i = 1;i<=maxi;i++){
            int extra = 0;
            for(int j = 0;j<D;j++){
                if(P[j]>i){
                    int tmp = P[j]-i;
                    extra += (tmp/i)+(tmp%i != 0);
                }
            }
            res = min(res, i+extra);
        }
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
}
