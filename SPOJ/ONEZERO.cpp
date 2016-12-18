/*
    Nimesh Ghelani (nims11)
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
    int foo[10][10];
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
    foo[i][j]=(i*j)%10;
    int n;
    in_T
    {
        in_I(n);
        pair<pair<int,int>,long long> tmp;
        queue <pair<pair<int,int>,long long> > BFS;
        int k = n%10;
        for(int i=1;i<10;i++)
        if(foo[i][k]==0)
        BFS.push(make_pair(make_pair(0,0),(n*i)/10));

        for(int i=1;i<10;i++)
        if(foo[i][k]==1)
        BFS.push(make_pair(make_pair(1,0),(n*i)/10));
long long ans;int lenans;
        while(!BFS.empty())
        {
            cout<<BFS.front().first.first<<" "<<BFS.front().first.second<<" "<<BFS.front().second<<endl;
            tmp = BFS.front();
            BFS.pop();
            int len=tmp.first.second;
            if(tmp.second == 0){ans = tmp.first.first,lenans=tmp.first.second;break;}
            int K = tmp.second%10;
            for(int i=0;i<10;i++)
            if((foo[i][k]+K)%10==0)
            BFS.push(make_pair(make_pair(tmp.first.first<<1,len+1),(n*i+tmp.second)/10));

            for(int i=0;i<10;i++)
            if((foo[i][k]+K)%10==1)
            BFS.push(make_pair(make_pair((tmp.first.first<<1)|1,len+1),(n*i+tmp.second)/10));
        }
//        cout<<ans<<endl;
        for(int i=0;i<=lenans;i++)
        printf("%d",(ans>>i)&1);
        newline;
    }
}
