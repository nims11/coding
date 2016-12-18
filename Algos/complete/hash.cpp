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
