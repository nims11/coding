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
#include<climits>
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
int n;
int arr[100];
bool check(long long cd, long long a){
    bool debug = false;
    if(cd == -3)debug = true;

    long long curr = a+cd;
    for(int i = 1;i<n;i++){
//        if(debug)cout<<curr<<endl;
        if(curr <= 0)return false;
        if(curr%arr[i])return false;
        long long tmp = curr/arr[i];
        if(tmp & (tmp-1))return false;
        curr += cd;
    }
    return true;
}
int main()
{
    in_T{
        in_I(n);
        for(int i = 0;i<n;i++)
            in_I(arr[i]);
        for(int i = 0;i<32;i++){
            for(int j = 0;j<32;j++){
                long long a = arr[0]*(1LL<<i);
                long long b = arr[1]*(1LL<<j);
                long long cd = b-a;
                if(check(cd,a)){
                    i = 40;
                    j = 40;
                    for(int x=0;x<n;x++){
//                        printf("%lld ", a+x*cd);
                        printf((x==n-1?"%lld\n":"%lld "), a+x*cd);
                    }
//                    newline;
                }
            }
        }
    }
}
