/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
long long gcd(long long a, long long b)
{
    return (b==0?a:gcd(b,a%b));
}
long long n,q,t,k,div_n,n2,tmp,ans;
long long cnt;
map<long long,int> divs;
map<long long, int>::iterator it;
int main()
{
    scanf("%lld%lld",&n,&q);
    int lt = sqrt(n);
    n2 = n;
    cnt = 0;
    div_n = 1;
    while(n2%2 == 0)
    {
        cnt++;
        n2 /= 2;
    }
    if(cnt)divs[2] = cnt;
    div_n *= (cnt+1);
    for(int i =3; i<=lt; i+=2)
    {
        if(n2%i == 0)
        {
            cnt = 0;
            while(n2%i == 0)
            {
                cnt++;
                n2 /= i;
            }
            div_n *= (cnt+1);
            divs[i] = cnt;
        }
    }
    if(n2>1)
    {divs[n2]=1;div_n*=2;}
//        for(it=divs.begin();it!=divs.end();it++)
//        cout<<(it->first)<<" "<<(it->second)<<endl;
    while(q--)
    {
        scanf("%lld%lld",&t,&k);
        switch(t)
        {
            case 1:
            tmp = gcd(n,k);
            ans = 1;
            it = divs.begin();
            while(tmp>1)
            {
                if(tmp%(it->first) == 0)
                {
                    cnt=0;
                    while(tmp%(it->first) == 0)
                    {
                        cnt++;
                        tmp /= (it->first);
                    }
                    ans*=(cnt+1);
                }
                it++;
            }
            printf("%lld\n",ans);
            break;

            case 2:
            if(n%k)
            {
                printf("0\n");
                break;
            }
            tmp = n/k;
            ans = 1;
            it = divs.begin();
            while(tmp>1)
            {
                if(tmp%(it->first) == 0)
                {
                    cnt=0;
                    while(tmp%(it->first) == 0)
                    {
                        cnt++;
                        tmp /= (it->first);
                    }
                    ans*=(cnt+1);
                }
                it++;
            }
            printf("%lld\n",ans);
            break;

            case 3:
            if(n%k)
            {
                printf("%lld\n",div_n);
                break;
            }
            tmp = n/k;
            ans = 1;
            it = divs.begin();
            while(tmp>1)
            {
                if(tmp%(it->first) == 0)
                {
                    cnt=0;
                    while(tmp%(it->first) == 0)
                    {
                        cnt++;
                        tmp /= (it->first);
                    }
                    ans*=(cnt+1);
                }
                it++;
            }
            printf("%lld\n",div_n-ans);
            break;
        }
    }
}
