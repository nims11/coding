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
char str[100010];
int len;
long long mod = 1000000009;
long long hashval[100010], hashval_rev[100010];
long long pow_10009[100010];
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
void computeHash(char *str, int len){
    hashval[0] = 0;
    hashval_rev[0] = 0;
    for(int i = 1;i<=len;i++){
        hashval[i] = ADD(hashval[i-1]*10009LL, str[i-1]);
        hashval_rev[i] = ADD(hashval_rev[i-1]*10009LL,  str[len-i]);
    }
    pow_10009[0] = 1;
    for(int i = 1;i<100010;i++)
        pow_10009[i] = MUL(pow_10009[i-1], 10009LL);
}
int substrHash(int i, int j){
    i++, j++;
    long long ret = hashval[j];
    long long tmp = hashval[i-1];
    tmp = tmp*pow_10009[j-i+1];
    tmp %= mod;
    ret = (ret - tmp)%mod;
    if(ret < 0)ret += mod;
    return ret;
}
int substrHash_rev(int i, int j){
    i++, j++;
    long long ret = hashval_rev[len-i+1];
    long long tmp = hashval_rev[len-j];
    tmp = tmp*pow_10009[j-i+1];
    tmp %= mod;
    ret = (ret - tmp)%mod;
    if(ret < 0)ret += mod;
    return ret;
}
int main()
{
    in_S(str);
    for(len=0;str[len];len++);
    computeHash(str, len);
    int Q,i,j,k,l,i2,j2;
    in_I(Q);
    while(Q--){
        in_I(i);in_I(j);in_I(k);in_I(l);
        i--, j--, k--, l--;
        swap(i, k);swap(j, l);
        if(k > j || l < i){
            if(substrHash(i, j) == substrHash_rev(i, j)){
                printf("Yes\n");
            }else
                printf("No\n");
        }else if(k <= i && l >= j){
            i2 = k+(l-j);j2 = l-(i-k);
            if(substrHash(i2, j2) == substrHash_rev(i2, j2)){
                printf("Yes\n");
            }else
                printf("No\n");
        }else if (k >= i && l <= j){
            long long hash1 = substrHash(i, k-1);
            long long hash1_r = substrHash_rev(i, k-1);
            long long hash2 = substrHash(k, l);
            long long hash2_r = substrHash_rev(k, l);
            long long hash3 = substrHash(l+1, j);
            long long hash3_r = substrHash_rev(l+1, j);
            int l1 = k-i, l2 = l-k+1, l3 = j-l;
            long long hashx = ADD(MUL(hash1, pow_10009[l2+l3]), MUL(hash2_r, pow_10009[l3]) + hash3);
            long long hashrev = ADD(MUL(hash3_r, pow_10009[l1+l2]), MUL(hash2, pow_10009[l1]) + hash1_r);
            if(hashx == hashrev){
                printf("Yes\n");
            }else
                printf("No\n");
        }else if(k >= i && l >= j){
            long long hash1 = substrHash(i, k-1);
            long long hash1_r = substrHash_rev(i, k-1);
            long long hash2 = substrHash(l-(j-k), l);
            long long hash2_r = substrHash_rev(l-(j-k), l);
            int l1 = k-i, l2 = j-k+1;
            if(ADD(MUL(hash1, pow_10009[l2]), hash2_r) == ADD(MUL(hash2, pow_10009[l1]), hash1_r)){
                printf("Yes\n");
            }else
                printf("No\n");
        }else if(k <= i && l <= j){
            long long hash1 = substrHash(k, k+l-i);
            long long hash1_r = substrHash_rev(k, k+l-i);
            long long hash2 = substrHash(l+1, j);
            long long hash2_r = substrHash_rev(l+1, j);
            int l1 = l-i+1, l2 = j-l;
            if(ADD(MUL(hash1_r, pow_10009[l2]), hash2) == ADD(MUL(hash2_r, pow_10009[l1]), hash1)){
                printf("Yes\n");
            }else
                printf("No\n");
        }else{
            return -1;
        }
    }
}
