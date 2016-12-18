/*
    Nimesh Ghelani (nims11)
    The multiple can be represented as bits
    do a BFS with dp state = modulo of number encountered
    store the modulo of the number in BFS.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int n;
    in_T
    {
        in_I(n);
        pair<long long, int> tmp,tmp2;
        queue <pair<long long, int> > BFS;
        BFS.push(make_pair(1,1%n));
        bool dp[20000];
        for(int i=0;i<n;i++)dp[i]=false;
        dp[1%n]=true;
        while(!BFS.empty())
        {
            tmp = BFS.front();
            if(tmp.second==0)break;
            BFS.pop();
            tmp2.first = (tmp.first<<1);
            tmp2.second = (tmp.second*10)%n;
            if(!dp[tmp2.second])
            {
                dp[tmp2.second]=true;
                BFS.push(tmp2);
            }
            tmp2.first = (tmp.first<<1)|1;
            tmp2.second = (tmp.second*10+1)%n;
            if(!dp[tmp2.second])
            {
                dp[tmp2.second]=true;
                BFS.push(tmp2);
            }
        }
        int i=63;
        long long ans = tmp.first;
        while((ans>>i &1)==0)i--;
        for(;i>=0;i--)
        P_I((ans>>i)&1);
        newline;
    }
}
