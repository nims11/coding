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
int sieve[100000];
vector<int> primes;
int genprimes(){
    for(int i = 2;i<100000;i++){
        if(sieve[i] == 0){
            primes.push_back(i);
            if(i*1LL*i < 100000)
                for(int j = i*i;j<100000;j+=i){
                    sieve[j] = 1;
                }
        }
    }
}
int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
//    genprimes();
    int n, k;
    in_I(n);
    in_I(k);
    vector<int> res[4];
    int st = 1, end = 6;
    for(int i = 0;i<n;i++){
        for(int mask = 0;mask<(1<<6);mask++){
            if(__builtin_popcount(mask) == 4){
                bool flag = true;
                for(int j = 0;j<6;j++){
                    for(int k = j+1;k<6;k++)
                        if((mask&(1<<j)) && (mask&(1<<k))){
                            if(GCD(st+j, st+k) != 1){
                                flag = false;
                                j = 10;
                                break;
                            }
                        }
                }
                if(flag){
                    for(int j = 0, cnt = 0;j<6;j++)
                        if(mask&(1<<j))
                            res[cnt++].push_back(st+j);
                    break;
                }
            }
        }
        st += 6;
        end +=6;
    }
    if(res[0].size() != n)
        cout<<"OOPS!"<<endl;
/*    printf("%d\n", k*res[3][res[3].size()-1]);*/
/*    for(int i = 0;i<res[0].size();i++){
        printf("%d %d %d %d\n", k*res[0][i], k*res[1][i], k*res[2][i], k*res[3][i]);
    }*/
}
