/*
ID: nimeshg1
PROG: sort3
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
ifstream fin("sort3.in");
ofstream fout("sort3.out");
#define cin fin
#define cout fout
int arr[1000];
int foo[4][4];
int nums[4];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        nums[arr[i]]++;
    }
    for(int i=0;i<nums[1];i++)
        foo[arr[i]][1]++;
    for(int i=nums[1];i<nums[1]+nums[2];i++)
        foo[arr[i]][2]++;
    for(int i=nums[1]+nums[2];i<n;i++)
        foo[arr[i]][3]++;

    int res = foo[2][1]+foo[3][1];
    if(foo[2][1]<=foo[1][2])
    {
        foo[2][2]+=foo[2][1];
        foo[3][2] += foo[1][2]-foo[2][1];
    }
    else
    {
        foo[2][2] += foo[1][2];
    }
    res += nums[2]-foo[2][2];
    cout<<res<<endl;
}
