/*
ID: nimeshg1
PROG: holstein
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
ifstream fin("holstein.in");
ofstream fout("holstein.out");
#define cin fin
#define cout fout
int V, G;
int req[25];
int feeds[15][25];
int res = (1<<30)-1;
int tmp[25];
bool test(int mask)
{
    int x = (mask == 1000);
    for(int i=0;i<V;i++)
        tmp[i] = 0;
    int i = 0;
    while(mask)
    {
        if(mask&1)
        {
            for(int j=0;j<V;j++)
                tmp[j] += feeds[i][j];
        }
        i++;
        mask>>=1;
    }
    for(int i=0;i<V;i++)
    {
        if(tmp[i]<req[i])
            return false;
    }
    return true;
}
int main()
{
    cin>>V;
    for(int i=0;i<V;i++)
        cin>>req[i];
    cin>>G;
    for(int i=0;i<G;i++)
        for(int j=0;j<V;j++)
            cin>>feeds[i][j];
    for(int i=1;i<(1<<G);i++)
    {
        if(__builtin_popcount(res)>__builtin_popcount(i) && test(i))
        {
            res = i;
        }
    }
    int num = __builtin_popcount(res);
    cout<<num<<" ";
    int found=0;
    for(int i=0;i<G;i++)
        if(res&(1<<i))cout<<i+1<<(++found!=num?" ":"");
    cout<<endl;
}
