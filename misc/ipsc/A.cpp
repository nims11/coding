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
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        sort(BE(str));
        reverse(BE(str));
        long long res = 0;
        for(int i = 1;i<(1<<str.length())-1;i++){
            long long x1, x2;
            x1 = x2 = 0;
            for(int j = 0;j<str.length();j++){
                if(i&(1<<j))
                    x1 = x1*10 + str[j] - '0';
                else
                    x2 = x2*10 + str[j] - '0';
            }
            res = max(res, x1+x2);
        }
        cout<<res<<endl;
    }
}
