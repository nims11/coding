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
    in_T
    {
        int n,m,k;
        cin>>n>>m>>k;
        string str;
        vector<int> on;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            int foo = 0;
            for(int j=0;j<str.length();j++)
                foo += (str[j]=='*');
            on.push_back(foo);
        }
        sort(on.begin(), on.end());
        int i=0;
        int ans = 0;
        for(;i<on.size()&&k;i++)
        {
            if(on[i]<m-on[i])
            {
                k--;
                on[i] = m-on[i];
            }else
            break;
        }
        k = k%2;
        if(k)
        {
            sort(on.begin(), on.end());
            on[0] = m-on[0];
        }
        for(i=0;i<on.size();i++)
            ans+=on[i];
        cout<<ans<<endl;
    }
}
