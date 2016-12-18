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
int C, Hr, Hb, Wr, Wb;
long long f(int x){
    long long rem = C - (Wr*1LL*x);
    if(x < 0 || rem < 0)return 0;
    // cout<<rem<<endl;
    long long s = x*1LL*Hr + rem/Wb*1LL*Hb;
    return s;
}
int main()
{
    cin>>C>>Hr>>Hb>>Wr>>Wb;
    long long res = 0;
    if(Wr <= 100000 && Wb <=100000){
        if(double(Hr)/Wr < double(Hb)/Wb)
            swap(Hr, Hb), swap(Wb, Wr);
        int maxi = C/Wr;
        for(int i = max(0, maxi-100010);i<=maxi;i++){
            res = max(res, f(i));
        }
    // }
    // else if(Wb <= 100000){
    //     swap(Hr, Hb);
    //     swap(Wr, Wb);
    //     int maxi = C/Wr;
    //     for(int i = max(0, maxi-100010);i<=maxi;i++)
    //         res = max(res, f(i));
    }else{
        if(Wr <= 100000)
            swap(Wr, Wb), swap(Hr, Hb);
        for(int i = 0;i<=100000;i++){
            res = max(res, f(i));
        }
    }
    cout<<res<<endl;
}
