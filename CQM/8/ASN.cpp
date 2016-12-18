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
vector<int> primes;
int sieve[10001];
int tmp[10001];
int main()
{
    primes.push_back(2);
    for(int i = 3;i<10001;i+=2){
        if(!sieve[i]){
            primes.push_back(i);
            for(int j = i*i;j<=10001;j+=i){
                sieve[j] = 1;
            }
        }
    }
    int N;
    while(in_I(N) != EOF){
        bool flag = false;
        bool ex = false;
        bool one = false;
        for(int i = 0;i<primes.size() && N>1;i++){
            int c = 0;
            while(N%primes[i] == 0)
                N/=primes[i], c++;
            if(c == 2 || c > 3)
            {
                flag =true;
                break;
            }
            if(c > 0 && ex){
                flag =true;
                break;
            }
            if(c == 3)
                ex = true;
            if(c == 1)
                one = true;
            if(c == 3 && one){
                flag =true;
                break;
            }
        }
        if(ex == true && N != 1){
            flag = true;
        }
        printf(flag?"YES\n":"NO\n");
    }
}
