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
#include<set>
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
int n, tmp;
vector<int> pos[4000];
map<int, int> elts;
vector<int> arr;
int ans  = 0;
void getans(int first, int second)
{
    int max_possible = 2*min(pos[first].size(), pos[second].size())+(pos[first].size()!=pos[second].size());
    if(max_possible<=ans)
        return;
    int orig = 1;
    int pos_1 = 0, pos_2 = 0;
    do
    {
        while(pos_2<pos[second].size() && pos[second][pos_2]<pos[first][pos_1])
            pos_2++;
        if(pos_2!=pos[second].size())
        {
            orig++;
            while(pos_1<pos[first].size() && pos[first][pos_1]<pos[second][pos_2])
            pos_1++;
            if(pos_1!=pos[first].size())
                orig++;
        }
        pos_2++;
    }while(pos_2<pos[second].size());
    ans = max(orig, ans);
//    cout<<first<<" "<<second<<" "<<orig<<endl;
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
    {
        in_I(tmp);
        if(elts.find(tmp) == elts.end())
        {
            elts[tmp] = arr.size();
            arr.push_back(tmp);
        }
        pos[elts[tmp]].push_back(i);
    }
    for(int i=0;i<arr.size();i++)
        ans = max(ans, (int)pos[i].size());
    int foo;
    for(int first = 0;first<arr.size();first++)
    {
        for(int second = 0;second<arr.size();second++)
        {
            if(first!=second)
                getans(first, second);
        }
    }
    cout<<ans<<endl;
}
