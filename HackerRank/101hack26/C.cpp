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
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
vector<int> A, B;
void getans(int idx, bool free=false){
    if(idx == A.size())return;
    if(A[idx] == -1){
        A[idx] = 0;
        getans(idx+1);
        return;
    }else if(B[idx] == -1){
        B[idx] = 0;
        getans(idx+1);
        return;
    }
    if(free){
        A[idx] = 9, B[idx] = 0;
        getans(idx+1, true);
    }else{
        if(A[idx] + B[idx] <= 9)
            getans(idx+1);
        else{
            getans(idx, true);
        }
    }
}
int main()
{
    in_T{
        A.clear();B.clear();
        long long N, M;
        in_L(N);
        in_L(M);
        while(N){
            A.push_back(N%10);
            N/=10;
        }
        while(M){
            B.push_back(M%10);
            M/=10;
        }
        while(A.size() < B.size())
            A.push_back(-1);
        while(B.size() < A.size())
            B.push_back(-1);
        reverse(BE(A));
        reverse(BE(B));
        getans(0);
        long long c = 0;
        for(int i = 0;i<A.size();i++){
            c = c*10 + ((A[i] + B[i])%10);
        }
        cout<<c<<endl;
    }
}
