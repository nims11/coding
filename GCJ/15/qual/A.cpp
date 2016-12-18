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
    in_T{
        z++;
        int n;string str;
        cin>>n>>str;
        int res = 0;
        int cur = 0;
        for(int i = 0;i<=n;i++){
            if(cur < i){
                res += (i-cur);
                cur = i;
            }
            cur += str[i] - '0';
        }
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
}
