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
int main()
{
    int z = 0;
    in_T{
        z++;
        int N, K, C, P;
        cin>>N>>K>>C;
        P = 1e9;
        for(int i = 0;i<N;i++){
            int x = K/(N-i);
            int y = K%(N-i);
            if(x == 0)
                continue;
            int jarsReq = C/x + (C%x != 0);
            int extraReq = 0;
            if(jarsReq > N-i){
                extraReq = C-(N-i)*x;
                jarsReq = N-i;
            }
            P = min(P, i+(extraReq?N-i-y:0));
        }
        cout<<"Case #"<<z<<": "<<C+P<<endl;
    }
}
