/*
    Nimesh Ghelani (nims11)
    just traverse through the tree in O(lg n)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
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
#define VVVV 36
long long pow_2[VVVV];
int main()
{
    pow_2[0] = 1;
    for(int i=1;i<VVVV;i++)
        pow_2[i] = pow_2[i-1]<<1;
//    cout<<pow_2[VVVV-1];
    long long n;
    while(1)
    {
        in_L(n);
        if(n==0)return 0;
        int max_lvl = int(upper_bound(pow_2, pow_2+VVVV, n)-pow_2);
        int lvl = 1;
        pair<long long, long long> curr = make_pair(1, 1);
        n %= pow_2[max_lvl-1];
        while(lvl<max_lvl)
        {
            if(n<pow_2[max_lvl-lvl-1])
            {
                curr.second += curr.first;
            }else
            {
                curr.first += curr.second;
                n -= pow_2[max_lvl-lvl-1];
            }
            lvl++;
        }
        printf("%lld/%lld\n", curr.first, curr.second);
    }
}
