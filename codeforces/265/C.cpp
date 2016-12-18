/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
long long remaps[10];
long long remapLength[10];
const int mod = 1000000007;
char str[100003];
int pow_10[100003];
int main()
{
    for(int i = 0;i<10;i++)remaps[i] = i, remapLength[i] = 10;
    pow_10[0] = 1;
    for(int i = 1;i<=100000;i++){
        pow_10[i] = (10LL*pow_10[i-1])%mod;
    }
    int k;
    vector<pair<int, string >  > maps;
    in_S(str);
    cin>>k;
    for(int i = 0;i<k;i++){
        int x;
        string str;
        cin>>x>>str;
        maps.push_back(make_pair(x,str));
    }
    for(int i = k-1;i>=0;i--){
        int curVal = 0;
        int curPow = 1;
        for(int j = 2;j<maps[i].second.length();j++){
            int c = maps[i].second[j]-'0';
            curVal =( ((curVal*remapLength[c])%mod) + remaps[c] )%mod;
            curPow = (curPow * remapLength[c])%mod;
        }
        remaps[maps[i].first] = curVal;
        remapLength[maps[i].first] = curPow;
    }
    int res = 0;
    for(int i = 0;str[i];i++){
        int c = str[i]-'0';
        res = (((res * remapLength[c]) % mod) + remaps[c])%mod;
    }
    printf("%d\n", res);
}
