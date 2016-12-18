/*
ID: nimeshg1
PROG: numtri
LANG: C++
*/
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
#include<fstream>
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
ifstream fin("numtri.in");
ofstream fout("numtri.out");
#define cin fin
#define cout fout
int dp[1001];
int arr[1001];
int main()
{
    int r;
    cin>>r;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
            cin>>arr[j];
        for(int j=i;j>0;j--)
            dp[j] = max(dp[j]+arr[j], dp[j-1]+arr[j]);
    }
    int ans = 0;
    for(int i=1;i<=r;i++)
        ans = max(ans, dp[i]);
    cout<<ans<<endl;
}
