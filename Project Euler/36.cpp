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
bool isP1(int x, int b){
    int x2 = 0;
    int x3 = x;
    while(x3){
        x2 = x2*b + (x3%b);
        x3 /= b;
    }
    return (x==x2);
}
int main()
{
    int res = 0;
    for(int i = 1;i<=1000000;i++){
        if(isP1(i, 10) && isP1(i, 2))
            res += i;
    }
    cout<<res<<endl;
}
