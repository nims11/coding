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
class node
{
    public:
    int n, last;
    node(){}
    node(int n,int last)
    {
        this->n = n;
        this->last = last;
    }
};
int main()
{
    int n,p;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>p;
    sort(arr[i], arr[i]+1);
    vector<node> dp[p+1];
    dp[0].push_back(node(0,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j+arr[i]<=p;j++)
        {
            for(int k=0;k<dp[j].size();k++)
            {
                if(dp[j][k].last < i)
                    dp[j+arr[i]].push_back(node(dp[j][k].n+1, i));
            }
        }
    }
    for(int i=0;i<n;i++)
    {

    }
}
