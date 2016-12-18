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
//vector<long long> sums[4];
long long unsigned r, t;
long long unsigned getres(long long mid)
{
    return 2*mid*r + mid*(2*mid-1);
}
int main()
{
//    for(int i=1;i<=4;i++)
//    {
//        sums[i-1].push_back(0);
//        long long x = i, y = 0;
//        while(y<=1000000000000000000LL)
//        {
//            y += x*x;
//            sums[i-1].push_back(y);
//            x+=4;
//        }
//    }
    int c = 0;
    in_T
    {
        c++;
        cin>>r>>t;
        long long unsigned start = 0, end = 1000000000;
        long long unsigned ans = 0;
        cout<<getres(2)<<endl;
        while(start<=end)
        {
            long long unsigned mid = (start+end)/2;
            long long unsigned res = getres(mid);
            if(res<=t)
                start = mid+1, ans = mid;
            else
                end = mid-1;
            cout<<start<<" "<<end<<endl;
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
}
