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
int n, max_num, min_num, max_f, min_f;
long long M = 1000000007;
int arr[100001];

int calc_substr()
{
    int n_max = 0, n_min = 0;
    int start = 0, end = 0;
    int ret = 0;
    for(;start<n;start++)
    {
        while((!n_max || !n_min) && end<=n)
        {
            n_max += (arr[end]==max_num);
            n_min += (arr[end]==min_num);
            end++;
        }
        if(n_max && n_min)
            ret = (ret + n-end+1)%M;
        else
            break;
        n_max -= (arr[start]==max_num);
        n_min -= (arr[start]==min_num);
    }
    return ret;
}
int pow_2(int r)
{
    int ret = 1;
    long long foo = 2;
    while(r)
    {
        if(r&1)
            ret=(ret*foo)%M;
        foo=(foo*foo)%M;
        r>>=1;
    }
    return ret;
}
int calc_subseq()
{
    if(max_num == min_num)
    {
        int a = pow_2(n) - 1;
        if(a==-1)a = M-1;
        return a;
    }
    long long a = pow_2(max_f) - 1;
    if(a==-1)a=M-1;
    int b = pow_2(min_f) - 1;
    if(b==-1)b=M-1;
    int c = pow_2(n-min_f-max_f);
//    cout<<a<<" "<<b<<" "<<c<<endl;
    return (((a*b)%M)*c)%M;
}
int main()
{
    in_T
    {
        in_I(n);
        max_num = 0;
        min_num = 200000;
        max_f = min_f = 0;
        for(int i=0;i<n;i++)
        {
            in_I(arr[i]);
            max_num = max(max_num, arr[i]);
            min_num = min(min_num, arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            max_f += (arr[i]==max_num);
            min_f += (arr[i]==min_num);
        }
        int ans1 = calc_substr();
        int ans2 = calc_subseq();
        printf("%d %d\n", ans1, ans2);
    }
}
