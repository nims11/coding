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
string str, str_rev;
int kmp_pi[2][300010];
void kmp_pre(string &str, int *kmp_pi){
    int m = str.size();
    kmp_pi[1] = 0;
    int k = 0;
    for(int q = 2;q<=m;q++){
        while(k>0 && str[k] != str[q-1])
            k = kmp_pi[k];
        if(str[k] == str[q-1])
            k++;
        kmp_pi[q] = k;
    }
}
int main()
{
    cin>>str;
    kmp_pre(str, kmp_pi[0]);
    str_rev = str;
    reverse(str_rev.begin(), str_rev.end());
    kmp_pre(str_rev, kmp_pi[1]);
    long long res = 0;
    int cur = kmp_pi[0][str.size()];
    while(cur > 0){
        if(cur <= (str.size()-1)/2){
            res++;
        }
        cur = kmp_pi[0][cur];
    }
    for(int i = 1;i<str.size();i++){
        for(int j = 0;j<2;j++)
        if(kmp_pi[j][i] >= (i+1)/2){
            int per = i - kmp_pi[j][i];
            if(i%per == 0 && (i/per)%2 == 0){
                res++;
            }
        }
    }
    cout<<res<<endl;
}
