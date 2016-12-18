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
int tmp[50];
long long getres(long long N){
    cout<<N<<endl;
    if(N < 0)return 0;
    if(N < 25)return tmp[N];
    long long cur = 25;
    while(cur <= N){
        cur *= 5;
    }
    cur /= 5;
    return getres(cur-1)*(N/cur) + getres(N%cur);
}
int main()
{
    for(int i = 0;i<25;i++)
        if(i%10 < 5)
            tmp[i] = 1;
    for(int i = 25;i<50;i++)
        if(i%10 >= 5)
            tmp[i] = 1;
    for(int i = 1;i<50;i++)
        tmp[i] += tmp[i-1];

    in_T{
        long long N;
        in_L(N);
        N = N - (N/125)*5;
        long long res = (N/50)*30;
                long long rem = N%50;
                        res += tmp[rem];
        printf("%lld\n",res);
    }
}
