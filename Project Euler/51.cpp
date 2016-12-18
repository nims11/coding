#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

#define MAX_N 10000000
int sieve[MAX_N+1];
set<int> primes;
void genPrimes(){
    sieve[1] = 1;
    for(int i = 2;i<=MAX_N;i+=1){
        if(sieve[i] == 0){
            primes.insert(i);
            if(i*1LL*i <= MAX_N)
            for(int j = i*i;j<=MAX_N;j+=i)
                sieve[j] = 1;
        }
    }
}
int foo[8][1<<8];
int getlen(int x){
    int lex = 0;
    while(x){
        lex++;
        x /= 10;
    }
    return lex;
}
int compo[10];
int main(){
    genPrimes();
    for(int p: primes){
        int cnt = 0;
        int p2 = p;
        while(p){
            compo[cnt++] = p % 10;
            p /= 10;
        }
        for(int i = 1;i<(1<<cnt);i++){
            bool flag = true;
            int bar = -1;
            for(int j = 0;j<cnt;j++){
                if((1<<j)&i){
                    if(bar == -1){
                        bar = compo[j];
                    }else if(bar != compo[j]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                int num = 0;
                for(int j = bool(i&(1<<(cnt-1)));j<10;j++){
                    int cur = 0;
                    for(int k = cnt-1;k>=0;k--){
                        cur *= 10;
                        if((1<<k)&i){
                            cur += j;
                        }else
                            cur += compo[k];
                    }
                    if(sieve[cur] == 0)
                        num++;
                }
                if(num == 8){
                    cout<<i<<" "<<p2<<endl;
                    return 0;
                }
            }
        }
    }
}
