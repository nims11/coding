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
int n, m;
int mices[131075], holes[131075];
bool foo(long long t){
    set<long long> freeHoles;
    for(int i = 0;i<m;i++)
        freeHoles.insert(holes[i]);
    set<long long>::iterator it;
    for(int i = 0;i<n;i++){
        it = freeHoles.lower_bound(mices[i]-t);
        if(it == freeHoles.end() || *it > mices[i]+t)
            return false;
        freeHoles.erase(it);
    }
    return true;
}
int main()
{
    in_T{
        in_I(n);
        in_I(m);
        for(int i = 0;i<n;i++)
            in_I(mices[i]);
        for(int i = 0;i<m;i++)
            in_I(holes[i]);
        sort(mices, mices+n);
        sort(holes, holes+m);
        long long st = 0, end = 0;
        for(int i = 0;i<n;i++)
            end += abs(mices[i]-holes[i]);
        while(st<end){
            long long mid = (st + end)/2;
            if(foo(mid))
                end = mid;
            else
                st = mid + 1;
        }
        cout<<st<<endl;
    }
}
