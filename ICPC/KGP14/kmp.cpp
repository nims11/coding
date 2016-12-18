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
int pi_P2[1000011];
char str1[1000011], str2[1000011];
int m1[1000011];
int len1, len2;

void computePI(char *P, int m, int* pi){
    pi[1] = 0;
    int k = 0;
    for(int q = 2;q<=m;q++){
        while(k>0 && P[k] != P[q-1]){
            k = pi[k];
        }
        if(P[k] == P[q-1])
            k++;
        pi[q] = k;
    }
}
void match(char *S, char *P, int n, int m, int *pi, int *mx){
    int q = 0;
    for(int i = 1;i<=n;i++){
        while(q>0 && P[q] != S[i-1])
            q = pi[q];
        if(P[q] == S[i-1])
            q++;
        mx[i] = q;
        if(q == m)
            q = pi[q];
    }
}
const int mod = 1000000007;
long long hash1[1000100], hash2[1000100];
long long POW(long long r, long long n)
{
    long long ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}

bool eq(int aend, int bst, int bend){
    long long h1 = hash1[aend+1];
    long long h2 = hash2[bend+1]-((hash2[bst]*POW(27, bend-bst+1))%mod);
//    cout<<aend<<" "<<bst<<" "<<bend<<endl;
//    cout<<h2<<endl;
    h2%=mod;
    if(h2<0)
        h2 += mod;
//    cout<<h1<<" "<<h2<<endl;
    return (h1 == h2);
}
int main()
{
    int z = 0;
    in_T{
        z++;
        printf("Case %d: ", z);
        in_S(str1);
        in_S(str2);
        int i;
        for(i = 1;str1[i-1];i++)
            hash1[i] = (hash1[i-1]*27 + str1[i-1]-'a' + 1)%mod,
            hash2[i] = (hash2[i-1]*27 + str2[i-1]-'a' + 1)%mod;
        len2 = len1 = i-1;
        computePI(str2, len2, pi_P2);
        match(str1, str2, len1, len2, pi_P2, m1);
        int res = 0;
        for(int i =1;i<=len1;i++){
            int a2 = m1[i];
            if(eq(i-a2-1, a2, i-1))
                res = i;
        }
        printf("%d\n", res);
    }
}
