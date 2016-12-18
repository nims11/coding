/*
ID: nimeshg1
PROG: ariprog
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
set<int> nums;
vector<pair<int, int> > res;
bool exist[125001];
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
#define cin fin
#define cout fout
int main()
{
    int n,m;
    int maxi = 0;
    cin>>n>>m;
    for(int i=0;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            nums.insert(i*i + j*j);
            exist[i*i + j*j] = 1;
        }
    }
    set<int>::iterator it, it2;
    for(it = nums.begin(); it != nums.end(); it++)
    {
//        cout<<*it<<endl;
        it2 = it;
        ++it2;
        int lt = (125000-*it)/(n-1);
        while(lt)
        {
            int i;
            for(i=1;i<n;i++)
            {
                if(!exist[*it + i*lt])
                    break;
            }
            if(i == n)
                res.push_back(make_pair(lt, *it));
            lt--;
        }
    }
    sort(res.begin(), res.end());
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].second<<" "<<res[i].first<<endl;
    }
    if(res.size() == 0)
    {
        cout<<"NONE"<<endl;
    }
}
