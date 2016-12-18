#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
#define MAX_N 3000000
int sieve[MAX_N+1];
vector<int> primes;
void genPrimes(){
    primes.push_back(2);
    for(int i = 3;i<=MAX_N;i+=2){
        if(sieve[i] == 0){
            primes.push_back(i);
            if(i*1LL*i <= MAX_N)
            for(int j = i*i;j<=MAX_N;j+=i)
                sieve[j] = 1;
        }
    }
}
int N, J;
int getans(int x, int base){
    int max_prime = primes.back();
    int max_repr = 0;
    for(int i = N-1;i>=0;i--){
        max_repr = max_repr*base;
        if(x&(1<<i))
            max_repr++;
        if(max_repr > max_prime)
            break;
    }
    max_prime = min(max_prime, max_repr-1);
    for(int i = 0;i<primes.size() && primes[i] <= max_prime;i++){
        int rem = 0;
        mod = primes[i];
        int foo = 0;
        for(int i = N-1;i>=0;i--){
            foo = MUL(foo,base);
            if(x&(1<<i))
                foo = ADD(foo, 1);
        }
        if(foo == 0)
            return mod;
    }
    return -1;
}
string repr(int x){
    string ret = "";
    for(int i = N-1;i>=0;i--){
        if(x&(1<<i))
            ret.push_back('1');
        else
            ret.push_back('0');
    }
    return ret;
}
int main(){
    genPrimes();
    int T;
    in_T{
        in_I(N);
        in_I(J);
        unsigned int x = 1;
        x |= (1<<(N-1));
        unsigned int y = 0;
        vector<int> res[11];
        while(1){
            int flag = true;
            int foo[11] = {0};
            for(int i = 2;i<=10;i++){
                int xx = getans(x+y, i);
                if(xx == -1){
                    flag = false;
                    break;
                }
                foo[i] = xx;
            }
            if(flag){
                res[0].push_back(x+y);
                for(int i = 2;i<=10;i++)
                    res[i].push_back(foo[i]);
            }
            y += 2;
            if(res[0].size() == J)
                break;
        }
        cout<<"Case #1:"<<endl;
        for(int i = 0;i<res[0].size();i++){
            cout<<repr(res[0][i])<<" ";
            for(int j = 2;j<=10;j++)
                cout<<res[j][i]<<" ";
            cout<<endl;
        }
    }
}
