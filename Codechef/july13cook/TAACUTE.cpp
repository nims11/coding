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
unsigned long long pre_hash[100001], suff_hash[100001];
unsigned long long POW(unsigned long long r, int n)
{
    unsigned long long ans = 1;
//    cout<<r<<" "<<n<<endl;
    while(n>0)
    {
        if(n&1)
            ans = ans*r;
        n >>= 1;
        r = r*r;
    }
    return ans;
}
pair<char, int> str[100001];
int K;
unsigned long long d = 1000000007;
unsigned long long POWd[200003];
unsigned long long calc_hash(int i, int j)
{
    if(i>j)
        return -1;
    unsigned long long ret = pre_hash[j] - POWd[2*(j-i+1)]*pre_hash[i-1];
    return ret;
}
unsigned long long calc_hash_rev(int i, int j)
{
    unsigned long long ret = suff_hash[j] - POWd[2*(j-i+1)]*suff_hash[i-1];
    return ret;
}
int pref_sum[100003];
int main()
{
    POWd[0] = 1;
    for(int i=1;i<=200002;i++)
        POWd[i] = POWd[i-1]*d;
    in_T
    {
        in_I(K);
        for(int i=1;i<=K;i++)
        {
            scanf("\n%c %d", &str[i].first, &str[i].second);
            pref_sum[i] = pref_sum[i-1] + str[i].second;
        }

        // prefix
        pre_hash[0] = 0;

        for(int i=1;i<=K;i++)
        {
            pre_hash[i] = pre_hash[i-1]*d + str[i].first;
            pre_hash[i] = pre_hash[i]*d + str[i].second;
        }
//        cout<<endl;

        // suffix
        suff_hash[0] = 0;
        for(int i=1;i<=K;i++)
        {
            suff_hash[i] = suff_hash[i-1]*d + str[K-i+1].first;
            suff_hash[i] = suff_hash[i]*d + str[K-i+1].second;
        }

//        for(int i=1;i<=K;i++)
//            for(int j=i;j<=K;j++)
//        {
//            cout<<i<<" "<<j<<" "<<calc_hash_rev(i, j)<<endl;
//        }
        long long ans = 0;
        // odd size
        for(int i = 1; i<= K; i++)
        {
            int st = 1;int  end = min(i, K-i+1);
            while(st < end)
            {
                int mid = (st+end+1)/2;
                if(calc_hash(i-mid+1, i) == calc_hash_rev(K-(i+mid-1)+1, K-i+1))
                    st = mid;
                else
                    end = mid-1;
            }
            int x = (pref_sum[i-1]-pref_sum[i-st])*2;
            ans += (x+1)/2 + 1LL*str[i].second*(str[i].second+1)/2;
            int a = i-st, b = i+st;
            if(a > 0 && b <= K)
            {
                if(str[a].first == str[b].first)
                    ans += min(str[a].second, str[b].second);
            }
        }
        // even
        for(int i = 1; i< K; i++)
        {
            int st = 1, end = min(i, K-i);
            if(calc_hash(i, i) != calc_hash_rev(K-(i+1)+1, K-(i+1)+1))
                continue;
            while(st < end)
            {
                int mid = (st+end+1)/2;
                if(calc_hash(i-mid+1, i) == calc_hash_rev(K-(i+mid)+1, K-(i+1)+1))
                    st = mid;
                else
                    end = mid-1;
            }
            int x = (pref_sum[i]-pref_sum[i-st])*2;
            ans += (x+1)/2;
            int a = i-st, b = i+st+1;
            if(a > 0 && b <= K)
            {
                if(str[a].first == str[b].first)
                    ans += min(str[a].second, str[b].second);
            }
        }
        printf("%lld\n", ans);
    }
}
