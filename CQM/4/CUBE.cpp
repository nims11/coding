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
int mapp[] = {0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
int getans(int n)
{
    int n2 = n;
    int len = 0;
    int mod = 1;
    while(n2)
    {
        n2/=10;len++;
        mod*=10;
    }
    int curr = mapp[n%10];
    vector<int> ans;
    ans.push_back(curr);
    n/=10;
    for(int i = 0, j =10;i<len;i++, j*=10)
    {
        long long foo = 3*curr*curr;
        for(int k = 0;k<10;k++)
        {
            if((foo*k)%10 == ((n-curr*curr*curr)%10+10)%10)
            {
                cout<<k<<endl;
                ans.push_back(k);
                break;
            }
        }
        n/=10;
        curr += j*ans.back();
    }
}
int main()
{
    in_T
    {
        int n;
        in_I(n);
        printf("%d\n", getans(n));
    }
}
