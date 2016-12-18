/*
    Nimesh Ghelani (nims11)
    If A, B, and AB are palindrome, both A and B must have same period.
    Find the period with KMP.
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
int n,l, base;
char str[2000003];
int pref_f[2000003];
const int d = 26;
int calc_pref_f(int n)
{
    pref_f[0] = 0;
    int k = 0;
    int size, period;
    for(int q=1;q<n;q++)
    {
        while(k && str[k] != str[q])
            k = pref_f[k-1];
        if(str[k] == str[q])
            k++;
        pref_f[q] = k;
//        cout<<k<<endl;
        if(k != 0 && (q+1)%(q+1-k) == 0)
            size = q+1, period = (q+1)/(q+1-k);
    }
    if(size == n)
    {
        return n/period;
    }else
        return n;
}
int main()
{
    in_I(n);
    long long unsigned H;
    map<long long unsigned, int> foo;
    map<long long unsigned, int>::iterator it;
    for(int i=0;i<n;i++)
    {
        in_I(l);
        in_S(str);
        base = calc_pref_f(l);
        H = 0;
        for(int j=0;j<base;j++)
            H = H*d + str[j]-'a';
        it = foo.find(H);
        if(it == foo.end())
            foo[H] = 1;
        else
            it->second++;
    }
    int res = 0;
    for(it = foo.begin(); it != foo.end(); it++)
    {
        l = it->second;
        res += l*(l-1);
    }
    res += n;
    printf("%d\n", res);
}
