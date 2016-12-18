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
int n;
int arr[1000000];
int main()
{
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        map<int, int> pref;
        map<int, int>::iterator it;
        pref[0] = 1;
        int p = 0;
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            p += arr[i];
            it = pref.find(p);
            if(it != pref.end())
            {
                ans += it->second;
                it->second++;
            }else
            pref[p] = 1;
        }
        printf("%lld\n", ans);
    }
}
