/*
ID: nimeshg1
PROG: frac1
LANG: C++
*/
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
#include<fstream>
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
ifstream fin("frac1.in");
ofstream fout("frac1.out");
#define cin fin
#define cout fout
set<pair<int, int> > foo;
int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first*b.second < b.first*a.second;
}
int main()
{
    int n;
    cin>>n;
    foo.insert(make_pair(0,1));
    foo.insert(make_pair(1,1));
    for(int den=1;den<=n;den++)
    {
        for(int num=1;num<den;num++)
        {
            if(GCD(den, num) == 1)
                foo.insert(make_pair(num, den));
        }
    }
    vector<pair<int, int> > res;
    for(set<pair<int, int> >::iterator it = foo.begin(); it!=foo.end(); it++)
    {
        res.push_back(*it);
    }
    sort(res.begin(), res.end(), cmp);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].first<<"/"<<res[i].second<<endl;
    }
}
