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
int n, m;
int main()
{
    {
        cin>>n;
        cin>>m;
        vector<int> res;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            int maxi = m;
            while(x--)
            {
                int y;
                cin>>y;
                maxi = min(maxi, y);
            }
            if(maxi<m)
                res.push_back(i+1);
        }
        cout<<res.size()<<endl;
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
}
