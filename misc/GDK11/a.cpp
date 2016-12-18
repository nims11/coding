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
int main()
{
    in_T{
        int n, m;
        in_I(n);in_I(m);
        int zero = 0;
        int ones = 0;
        if(n == 0){
            zero++;
        }else
        while(n){
            if(n%2 == 0)
                zero++;
            else
                ones++;
            n >>= 1;
        }
        n = m;
        if(n == 0){
            zero++;
        }else
        while(n){
            if(n%2 == 0)
                zero++;
            else
                ones++;
            n >>= 1;
        }
        int maxi = 0, mini = 0;
        for(int i = 0;i<ones;i++)
            maxi = (maxi<<1)|1;
        for(int i = 0;i<zero;i++)
            maxi <<= 1;
        if(ones){
            mini = 1;
            ones--;
            for(int i = 0;i<zero;i++)
                mini <<= 1;
            for(int i = 0;i<ones;i++)
                mini = (mini<<1)|1;
        }
        cout<<mini<<" "<<maxi<<endl;
    }
}
