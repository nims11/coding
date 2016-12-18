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
    int n;
    in_I(n);
    vector<int> loc[n];
    int new_row_loc[n], old_row_loc[n], new_col_loc[n], old_col_loc[n];
    for(int i=0;i<n;i++)
        new_row_loc[i] = old_row_loc[i] = i, new_col_loc[i] = old_col_loc[i] = i;
    pair<int, int> row_size[n], col_size[n];
    for(int i=0;i<n;i++)
        row_size[i].first = 0, col_size[i].first = 0, row_size[i].second = i, col_size[i].second = i;
    int tmp1, tmp2;
    for(int i=0;i<n-1;i++)
    {
        in_I(tmp1);
        in_I(tmp2);
        loc[tmp1-1].push_back(tmp2-1);
        row_size[tmp1-1].first++;
        col_size[tmp2-1].first++;
    }
    sort(row_size, row_size+n);
    for(int i=0;i<n;i++)
        sort(loc[i].begin(), loc[i].end());
    vector<pair<int, pair<int, int>  > > ans;
    for(int i=n-1;i>=0 && row_size[i].first;i--)
    {
        int sw1 = i;
        int sw2 = new_row_loc[row_size[i].second];
        if(sw1 == sw2)
            continue;
        int tmp1 = new_row_loc[old_row_loc[sw1]];
        int tmp2 = new_row_loc[old_row_loc[sw2]];
        new_row_loc[old_row_loc[sw1]] = sw2;
        new_row_loc[old_row_loc[sw2]] = sw1;
        old_row_loc[sw1] = tmp2;
        old_row_loc[sw2] = tmp1;
        ans.push_back(make_pair(1,make_pair(sw1+1, sw2+1)));

    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
    }
}
