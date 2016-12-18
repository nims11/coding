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
int id[30];
int sum[30];
vector<pair<int,int> > sum_possible[2001];
int n;
int foo;
bool getans(int node, int mask)
{
    if(mask==foo)
    return true;
    for(int i=0;i<sum_possible[sum[node]].size() && sum_possible[sum[node]][i].second!=-1;i++)
    {
    int tmp = (1<<sum_possible[sum[node]][i].first)|(1<<sum_possible[sum[node]][i].second);
    if(!(mask&&tmp))
    {
    if(getans(sum_possible[sum[node]][i].first, mask|tmp) && getans(sum_possible[sum[node]][i].second, mask|tmp))
    return true;
    }
    }
    for(int i=0;i<n;i++)
    {
    if(i!=node && sum[node]==id[i])
    return getans(i, mask | (1<<i));
    }
    return false;
}
int main()
{
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d", &id[i], &sum[i]);
        }
        for(int i=0;i<2001;i++)
            sum_possible[i].clear();
        for(int i=0;i<n;i++)
        {
            sum_possible[id[i]].push_back(make_pair(i, -1));
            for(int j=i+1;j<n;j++)
            {
//                sum_possible[id[i]+id[j]].push_back((1<<i)||(1<<j));
                sum_possible[id[i]+id[j]].push_back(make_pair(i,j));
            }
        }
        int ances[n];
        for(int i=0;i<n;i++)
            ances[i] = 0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<sum_possible[sum[i]].size();j++)
            {
                if(sum_possible[sum[i]][j].second==-1)
                {
                    ances[sum_possible[sum[i]][j].first] |= 1<<i;
                }else
                {
                    ances[sum_possible[sum[i]][j].first] |= 1<<i;
                    ances[sum_possible[sum[i]][j].second] |= 1<<i;
                }
            }
        }
        foo = 1<<n - 1;
        for(int i=0;i<n;i++)
        {
            bool flag = true;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(ances[j]&(1<<i))
                    {

                    }else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag && getans(i, 1<<i))
                ans.push_back(id[i]);
        }
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        newline;
    }
}
