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
const long long MAX_L = 1000000000000000000LL;
const long long MAX_I = 1000000000LL;
set<long long> res;
int main()
{
    long long n;
    cin>>n;
    long long a = 2;
    while(a<=MAX_I)
    {
        long long start = 1, end = MAX_I;
        long long s1 = start*start + start*(a-3) - 2*n;
        long long s2 = end*end + end*(a-3) - 2*n;
        if(s1<=0 && s2>=0)
        {
            while(start<=end)
            {
                long long mid = (start+end)/2;
                long long s1 = mid*mid + mid*(a-3) - 2*n;
                if(s1 == 0)
                {
                    cout<<a<<" "<<mid<<endl;
                    res.insert(a*mid/2);
                    break;
                }else if(s1<0)
                    start = mid+1;
                else end = mid-1;
            }
        }
        a <<= 1;
    }
    if(res.size() == 0)
        cout<<-1<<endl;
    for(set<long long>::iterator it = res.begin(); it != res.end(); it++)
    {
        cout<<*it<<endl;
    }
}
