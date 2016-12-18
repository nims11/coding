/*
ID: nimeshg1
PROG: barn1
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
#include<fstream>
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
ifstream fin("barn1.in");
ofstream fout("barn1.out");
int main()
{
    int m,s,c;
    fin>>m>>s>>c;
    vector<int> diff;
    vector<int> arr;
    for(int i=0;i<c;i++)
    {
        int tmp;
        fin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<arr.size();i++)
        diff.push_back(arr[i]-arr[i-1]);
    sort(diff.begin(),diff.end());
    int ans = arr[arr.size()-1] - arr[0] +1;
//    cout<<ans<<endl;
    for(int i=0;i<diff.size() && i<m-1;i++)
        ans -= diff[diff.size()-i-1] -1;
    fout<<ans<<endl;
//    cout<<ans<<endl;
}
