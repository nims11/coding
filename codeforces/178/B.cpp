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
int main()
{
    int n;
    cin>>n;
    vector<int> w[2];
    w[0].push_back(0);
    w[1].push_back(0);
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        w[x-1].push_back(y);
    }
    sort(w[0].begin(), w[0].end());
    sort(w[1].begin(), w[1].end());
    for(int i=1;i<w[0].size();i++)
        w[0][i] += w[0][i-1];
    for(int i=1;i<w[1].size();i++)
        w[1][i] += w[1][i-1];

    int ans = 1000000;
    for(int i=0;i<w[0].size();i++)
    {
        for(int j=0;j<w[1].size();j++)
        {
            if(w[0][i]+w[1][j]<=(w[0].size()-i-1)+2*(w[1].size()-j-1))
                ans = min(ans, (int)(w[0].size()-i-1)+2*int(w[1].size()-j-1));
        }
    }
    cout<<ans<<endl;
}
