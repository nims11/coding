/*
    Nimesh Ghelani (nims11)
    Rabin Karp + Hashing
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
#include<cmath>
#include<stack>
#include<cassert>
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
int n,a,b,q;
vector<int> hash[100000];
int len[100000];
const int mod = 1000003;
const int d = 26;
int getans(int a, int b)
{
    int start = 0;
    int end = min(len[a], len[b]);
    while(start<end)
    {
//        cout<<start<<" "<<end<<endl;
        int mid = (start+end)/2;
        if(mid == start)
            mid = end;
        if(hash[a][mid] == hash[b][mid])
        {
            start = mid;
        }else
        {
            end = mid - 1;
        }
    }
    return start;
}
char tmp[500005];
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
    {
        in_S(tmp);
        len[i] = strlen(tmp);
        hash[i].push_back(0);
        for(int j=1;j<=len[i];j++)
        {
            hash[i].push_back((hash[i][j-1]*d + tmp[j-1] - 'a')%mod);
        }
    }
    in_I(q);
    while(q--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", getans(a, b));
    }
}
