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
int N;
int main()
{
    in_T
    {
        in_I(N);
        int bits[32] = {0};
        int pref[32] = {0};
        int highest = 0;
        for(int i = 0;i<32;i++)
        {
            bits[i] = bool(N&(1<<i));
            if(bits[i])
                highest = i;
        }
        pref[0] = bits[0];
        for(int i = 1;i<32;i++)
            pref[i] = pref[i-1] + bits[i];

        if(pref[31] == 1)
        {
            printf("%d\n", highest-1);
            continue;
        }
        int res = 1000000000;
        for(int i = highest-1;i>=0;i--)
        {
            if(bits[i])
            {
                int loc1 = highest + pref[highest-1]-pref[i];
                int loc2 = i;
                int rem = pref[i-1];
//                cout<<loc1<<" "<<loc2<<" "<<rem<<endl;
                while(rem)
                {
                    if(loc2>loc1)
                        loc1++;
                    else
                        loc2++;
                    rem--;
                }
                res = min(res, max(loc1, loc2));
            }
        }
        printf("%d\n", res);
    }
}
