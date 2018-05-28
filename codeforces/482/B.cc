#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;

const int mod = 1000000007;

using namespace std;

int main(){
    long long n;
    cin>>n;
    string kuro, shiro, katie;
    cin>>kuro>>shiro>>katie;
    long long kuro_[256] = {0};
    long long shiro_[256] = {0};
    long long katie_[256] = {0};
    for(char ch: kuro)
        kuro_[ch]++;
    for(char ch: shiro)
        shiro_[ch]++;
    for(char ch: katie)
        katie_[ch]++;

    long long kuro_max=0, shiro_max=0, katie_max = 0;
    for(int i = 0; i < 256; i++){
        if((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
            ;
        else
            continue;
        if(kuro_[i] + n - (long long)kuro.length() > 0){
            long long rem = kuro_[i] + n - (long long)kuro.length();
            if(rem % 2 == 0 || rem % kuro.length() == 0)
                kuro_max = max(kuro_max, (long long)kuro.length());
            else
                kuro_max = max(kuro_max,(long long) kuro.length()-1);
        }
        else
            kuro_max = max(kuro_max, kuro_[i] + n);

        if(shiro_[i] + n - (long long)shiro.length() > 0){
            long long rem = shiro_[i] + n - (long long)shiro.length();
            if(rem % 2 == 0 || rem % shiro.length() == 0)
                shiro_max = max(shiro_max, (long long)shiro.length());
            else
                shiro_max = max(shiro_max, (long long)shiro.length()-1);
        }
        else
            shiro_max = max(shiro_max, shiro_[i] + n);

        if(katie_[i] + n - (long long)katie.length() > 0){
            long long rem = katie_[i] + n - (long long)katie.length();
            if(rem % 2 == 0 || rem % katie.length() == 0)
                katie_max = max(katie_max, (long long)katie.length());
            else
                katie_max = max(katie_max, (long long)katie.length()-1);
        }
        else
            katie_max = max(katie_max, katie_[i] + n);
    }

    if(kuro_max > max(shiro_max, katie_max))
        cout<<"Kuro"<<endl;
    else if(shiro_max > max(kuro_max, katie_max))
        cout<<"Shiro"<<endl;
    else if(katie_max > max(kuro_max, shiro_max))
        cout<<"Katie"<<endl;
    else
        cout<<"Draw"<<endl;
}
