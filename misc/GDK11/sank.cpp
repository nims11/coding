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
        in_I(n);
        in_I(m);
        map<long long, int> foo;
        assert(m <= 100 && m >= 0);
        long long x, sum = 0;
        foo[0]  = 1;
        long long res = 0;
        for(int i = 0;i<n;i++){
            in_L(x);
            sum = (sum + x)%m;
            if(sum < 0)sum += m;
            // cout<<sum<<endl;
            if(foo.find(sum) == foo.end())
                foo[sum] = 0;
            res += foo[sum];
            foo[sum]++;
        }
        printf("%lld\n", res);
    }
}
