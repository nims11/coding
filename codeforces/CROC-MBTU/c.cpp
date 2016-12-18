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
int main()
{
    int tmp,n,k;
    cin>>n>>k;
    vector<int> foo;
    foo.push_back(0);
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        foo.push_back(tmp);
    }
    foo.push_back(0);
    int start,end,pre;
    int ans[k+1];
    for(int i=1;i<=k;i++)ans[i]=0;
    for(int i=1;i<=n;)
    {
        start= i;
        while(foo[i]==foo[start])i++;

        if(foo[start-1]==foo[i])ans[foo[start]]+=2;
        else
        ans[foo[start]]++;
    }
    int mini=0, minj=1;
    for(int i=1;i<=k;i++)
    {
//        cout<<ans[i]<<endl;
        if(ans[i]>mini)
        {
            mini=ans[i];
            minj = i;
        }
    }
    cout<<minj<<endl;
}
