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
int n;
char str[103][103];
bool col_solve()
{
    vector<pair<int, int> > ans;
    for(int i=0;i<n;i++)
    {
        bool flag = false;
        for(int j=0;j<n;j++)
        {
            if(str[j][i] == '.')
            {
                flag = true;
                ans.push_back(make_pair(j, i));
                break;
            }
        }
        if(!flag)
            return false;
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    return true;
}
bool row_solve()
{
    vector<pair<int, int> > ans;
    for(int i=0;i<n;i++)
    {
        bool flag = false;
        for(int j=0;j<n;j++)
        {
            if(str[i][j] == '.')
            {
                flag = true;
                ans.push_back(make_pair(i, j));
                break;
            }
        }
        if(!flag)
            return false;
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    return true;
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
        in_S(str[i]);
    if(!col_solve() && !row_solve())
    {
        cout<<-1<<endl;
    }
}
