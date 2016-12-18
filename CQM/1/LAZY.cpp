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
int main()
{
    in_T
    {
        int r,c;
        in_I(r);in_I(c);
        int a[r][c];
        for(int i = 0; i<r; i++)
            for(int j = 0; j<c; j++)
            in_I(a[i][j]);
        int ans = 0;
        for(int i = 0; i<r; i++)
            for(int j = 0; j<c; j++)
            {
                if(a[i][j] == 1)
                {
                    if(i-1<0 || a[i-1][j] == 0)
                        ans++;
                    if(i+1>=r || a[i+1][j] == 0)
                        ans++;
                    if(j-1<0 || a[i][j-1] == 0)
                        ans++;
                    if(j+1>=c || a[i][j+1] == 0)
                        ans++;
                }
            }
        cout<<ans<<endl;
    }
}
