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
int fact[10];
bool foo(int x){
    int xx = 0;
    int x2 = x;
    while(x){
        xx += fact[x%10];
        x/=10;
    }
    return (xx == x2);
}
int main()
{
    fact[0] = 1;
    for(int i = 1;i<10;i++)
        fact[i] = i*fact[i-1];
    long long res = 0;
    for(int i = 10;i<=400000;i++){
        if(foo(i))
            res += i;
    }
    cout<<res<<endl;
}
