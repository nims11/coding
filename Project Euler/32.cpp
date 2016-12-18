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
bool isPan(int a, int v, int p){
    unsigned int xx = 0;
      while(a){
        int m = a%10;
        a/=10;
        if(xx & (1<<m))
            return false;
        xx |= (1<<m);
    }
      a = v;
   while(a){
        int m = a%10;
        a/=10;
        if(xx & (1<<m))
            return false;

        xx |= (1<<m);
    }
   a = p;
   while(a){
        int m = a%10;
        a/=10;
        if(xx & (1<<m))
            return false;

        xx |= (1<<m);
    }
   return (xx == (1<<10)-2);
}
int main()
{
    set<int> foo;
    const int maxn = 9999999;
    int lt = sqrt(maxn);
    long long res = 0;
    for(int i = 1;i<=lt;i++){
        for(int j = 1;j<=lt;j++){
            int p = i*j;
            if(foo.find(p) != foo.end())continue;
            if(isPan(i, j, p))
                res += p, foo.insert(p);
        }
    }
    cout<<res<<endl;
}
