/*
    Nimesh Ghelani (nims11)
    Rabin Karp + Hashing
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
#include<cstring>
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
#define IS_LOWER(a) (a>='a' && a<='z')
using namespace std;
const int mod = 10000019;
char str[100005];
const int d = 52;

int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int get_d(char ch)
{
    if(IS_LOWER(ch))
        return ch-'a';
    else
        return ch-'A'+26;
}
int main()
{
    while(in_S(str) != EOF)
    {
        int hash1 = 0;
        int hash2 = 0;
        int n = strlen(str);
        for(int i=0;i<n/2;i++)
        {
            hash1 = (hash1*d + get_d(str[i]))%mod;
            hash2 = (hash2*d + get_d(str[n-i-1]))%mod;
        }
        int res = 0;
        int curr1 = 0, curr2 = n/2 + n%2;
        int curr_len = n/2;
//        cout<<curr1<<" "<<curr2<<" "<<curr_len<<" "<<hash1<<" "<<hash2<<endl;
        if(hash1 == hash2)
        {
            printf("%s\n", str);
            continue;
        }else
        for(int i=n+1;curr_len;i++)
        {
//            cout<<i<<endl;
            if(i%2 == 1)
            {
                hash1 = (hash1 - POW(d, curr_len-1)*get_d(str[curr1++]))%mod;
                if(hash1<0)hash1 += mod;
                hash2 = (hash2 - get_d(str[curr2++]))%mod;
                if(hash2<0)hash2 += mod;
                hash2 = (hash2*1LL*POW(d, mod-2))%mod;
                curr_len--;
            }else
            {
                hash1 = (hash1 - POW(d, curr_len-1)*get_d(str[curr1++]))%mod;
                hash1 = (hash1*d + get_d(str[curr2-1]))%mod;
                if(hash1<0)hash1 += mod;
            }
//            cout<<curr1<<" "<<curr2<<" "<<curr_len<<" "<<hash1<<" "<<hash2<<endl;
            if(hash1 == hash2)
            {
                res = curr_len;
                break;
            }
        }
        printf("%s",str);
        for(int i=curr1-1;i>=0;i--)
            printf("%c", str[i]);
        newline;
    }
}
