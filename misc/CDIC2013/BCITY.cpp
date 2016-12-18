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
#include <cstring>
using namespace std;
int tmp;
vector<int> foo[100001];
int done[100001];
int main()
{
    in_T
    {
        int n, k;
        in_I(n);in_I(k);
        memset(done, 0, sizeof(done));
        for(int i=0;i<n;i++)
        {
            in_I(tmp);
            if(!done[tmp])
                foo[tmp].clear(), done[tmp] = true;
            foo[tmp].push_back(i);
        }
        int ans = 1;
        for(int i=1;i<100001;i++)
        {
            if(done[i])
            {
                int start = 0;
                int curr_ans = 1, curr_k = 0;
                for(int j=1;j<foo[i].size();j++)
                {
                    curr_ans++;
                    curr_k += foo[i][j]-foo[i][j-1] - 1;
                    while(curr_k>k)
                    {
                        start++;
                        curr_ans--;
                        curr_k -= foo[i][start]-foo[i][start-1] - 1;
                    }
                    ans = max(ans, curr_ans);
                }
            }
        }
        printf("%d\n", ans);
    }
}
