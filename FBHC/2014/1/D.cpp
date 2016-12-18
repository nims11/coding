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
#define MAXN 50
using namespace std;
int GCD(int a,int b)
{
    if(b != 0)
        while(b^=a^=b^=a%=b);
    return a;
}
int N, K, A[50];
int main()
{
    int z = 0;
    in_T{
        z++;
        cin>>N>>K;
        for(int i = 0;i<N;i++)cin>>A[i];
        map<long long, long long> *st = new map<long long, long long>;
        map<long long, long long>::iterator it;
        for(int i = A[0]/K + (A[0]%K != 0); i <= 200; i++)
            (*st)[i] = K*1LL*i-A[0];
        for(int i = 1; i<N;i++){
            cerr<<st->size()<<" "<<i<<endl;
            map<long long, long long> *st2 = new map<long long, long long>;
            int sz = 0;
            for(it = st->begin(); it != st->end() && sz < 100000; it++)
            for(int j = A[i]/K + (A[i]%K != 0); j<=200;j++, sz++)
                if(GCD(j, it->first) == 1)
                {
                    (*st2)[j*1LL*it->first] = it->second + K*1LL*j-A[i];
                }

            delete st;
            st = st2;
        }
        long long res = 1e9;
        for(it = st->begin(); it != st->end(); it++)
            res = min(res, it->second);
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
}
