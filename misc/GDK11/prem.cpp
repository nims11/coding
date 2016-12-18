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
char str[200];
long long hashv;
int mod = 1000000007;
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int main()
{
    in_T{
        map<int, int> hashes;
        in_S(str);
        int l = strlen(str);
        int res = 0;
        for(int i = 0;i<l;i++){
            hashv = 0;
            for(int j = i;j<l;j++){
                hashv = (hashv + POW(27, 1+str[j]-'A'))%mod;
                if(hashes.find(hashv) == hashes.end())
                    hashes[hashv] = 0;
                res += hashes[hashv];
                hashes[hashv]++;
            }
        }
        printf("%d\n", res);
    }
}
