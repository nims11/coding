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
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
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
struct player{
    string name;
    int shot, height;
    int time, rating;
}players[50];
bool cmp1(const player &a, const player &b)
{
    if(a.shot != b.shot)
        return a.shot < b.shot;
    return a.height < b.height;
}
bool cmp_H(const player &a, const player &b)
{
    if(a.time != b.time)
        return a.time<b.time;
    return a.rating<b.rating;
}
int main()
{
    int z = 0;
    in_T
    {
        z++;
        int N, M, P;
        cin>>N>>M>>P;
        for(int i = 0;i<N;i++)
        {
            cin>>players[i].name>>players[i].shot>>players[i].height;
            players[i].time = 0;
        }
        sort(players, players + N, cmp1);
        vector<player> T[2];
        for(int i = 0;i<N;i++)
        {
            players[i].rating = N-i;
            T[i%2].push_back(players[i]);
        }

        sort(T[0].begin(), T[0].end(), cmp_H);
        sort(T[1].begin(), T[1].end(), cmp_H);

        for(int i = 0;i<M;i++)
        {
            for(int j = 0; j<P; j++)
                T[0][j].time++, T[1][j].time++;
            for(int z= 0 ;z<2;z++)
            {
                if(T[z].size() > P)
                {
                    sort(T[z].begin(), T[z].begin()+P, cmp_H);
                    sort(T[z].begin()+P, T[z].end(), cmp_H);
                    swap(T[z][P-1], T[z][P]);
                }
            }
        }
        vector<string> ans;
        for(int i = 0;i<P;i++)
            ans.push_back(T[0][i].name), ans.push_back(T[1][i].name);
        sort(ans.begin(), ans.end());
        cout<<"Case #"<<z<<":";
        for(int i = 0;i<ans.size();i++)
            cout<<" "<<ans[i];
        cout<<endl;
    }
}
