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
vector<long long> res;
int pow_10[10];
bool is_palin(long long n)
{
    long long n_rev = 0;
    long long n_st = n;
    while(n)
    {
        n_rev = n_rev*10 + n%10;
        n /= 10;
    }
    return (n_rev == n_st);
}
void foobar(int tmp[], int cnt)
{
    long long n = 0;
    for(int i=0;i<cnt;i++)
    {
        n = n*10 + tmp[i];
    }
    if(is_palin(n*n))
        res.push_back(n*n);
}
void init()
{
    pow_10[0] = 1;
    for(int i=1;i<10;i++)
        pow_10[i] = 10*pow_10[i-1];
    int tmp[10];
    for(int len = 1; len<=7; len++)
    {
        int half = len/2;
        int mid = len%2;
        int lt = pow_10[half];

        for(int i=1;i<lt;i++)
        {
            int cnt = 0;
            int a = i;
            while(cnt < half)
            {
                tmp[cnt++] = a%10;
                a/=10;
            }
            if(mid)
            {
                for(int j=0;j<10;j++)
                {
                    tmp[cnt++] = j;
                    for(int k=0;k<half;k++)
                        tmp[cnt++] = tmp[half-k-1];
                    foobar(tmp, cnt);
                }
            }else
            {
                for(int k=0;k<half;k++)
                    tmp[cnt++] = tmp[half-k-1];
                foobar(tmp, cnt);
            }
        }
    }
}
int main()
{
    for(int i=1;i<=1000;i++)
        if(is_palin(i) && is_palin(i*i))
            cout<<i*i<<endl;
//    init();
//    sort(res.begin(), res.end());
//    int c =0;
//    in_T
//    {
//        c++;
//        cout<<"Case #"<<c<<": ";
//        long long a,b;
//        cin>>a>>b;
//        cout<<int(upper_bound(res.begin(), res.end(), b) - lower_bound(res.begin(), res.end(), a))<<endl;
//    }
}
