/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
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
vector<pair<int, int> > arr;
pair<int, int> tmp;
bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second<b.second;
}
int main()
{
    arr.push_back(make_pair(1,1));
    int n=1;
    int curr=2;
    int tmp2=0;
    while(n<1000000)
    {
        tmp = arr[tmp2++];
        n+=tmp.second*tmp.first;
        while(tmp.second--)
        arr.push_back(make_pair(curr++, tmp.first));
    }
    for(int i=1;i<arr.size();i++)
        arr[i].second += arr[i-1].second;
    int c=0;
    in_T
    {
        c++;
        int n;
        in_I(n);
        printf("Case #%d: %d\n", c,lower_bound(arr.begin(), arr.end(),make_pair(0,n), comp)->first);
    }
}
