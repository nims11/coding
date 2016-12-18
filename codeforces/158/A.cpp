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
    int a,b,n;cin>>a>>b>>n;
    vector<int> ans;
    ans.push_back(a);

    for(int i=0;i<10;i++)
    {
        int foo = a*10+i;
        if(foo%b==0)
        {
            ans.push_back(i);
            break;
        }
    }

    if(ans.size()!=2)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(int i=1;i<n;i++)
    {
        ans.push_back(0);
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i];
    newline;
}

