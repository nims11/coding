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
vector<int> neigh[50];
bool visi[50];
int teams3[50][3], teams2[50][2], teams1[50];
int cnt1, cnt2, cnt3;
int cnt = 0;
vector<int> tmp;
void dfs(int x)
{
    tmp.push_back(x);
    for(int i=0;i<neigh[x].size();i++)
    {
        if(!visi[neigh[x][i]])
        {
            visi[neigh[x][i]] = true;
            dfs(neigh[x][i]);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        in_I(a);
        in_I(b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        tmp.clear();
        if(!visi[i])
        {
            visi[i] = true;
            dfs(i);
            if(tmp.size() >3)
            {
                cout<<-1<<endl;
                return 0;
            }else if(tmp.size() ==3)
            {
                teams3[cnt3][0] = tmp[0], teams3[cnt3][1] = tmp[1], teams3[cnt3][2] = tmp[2];
                cnt3++;
            }else if(tmp.size() == 2)
            {
                teams2[cnt2][0] = tmp[0], teams2[cnt2][1] = tmp[1];
                cnt2++;
            }else if(tmp.size() == 1)
            {
                teams1[cnt1] = tmp[0];
                cnt1++;
            }
        }
    }
    for(int i=0;i<min(cnt2, cnt1); i++)
    {
        teams3[cnt3][0] = teams1[i];
        teams3[cnt3][1] = teams2[i][0];
        teams3[cnt3][2] = teams2[i][1];
        cnt3++;
    }
    if(cnt2>cnt1)
    {
        cout<<-1<<endl;
        return 0;
    }else
    {
        for(int i=cnt2;i<cnt1;i+=3)
        {
            teams3[cnt3][0] = teams1[i];
            teams3[cnt3][1] = teams1[i+1];
            teams3[cnt3][2] = teams1[i+2];
            cnt3++;
        }
    }
    for(int i=0;i<cnt3;i++)
    {
        cout<<teams3[i][0]<<" "<<teams3[i][1]<<" "<<teams3[i][2]<<endl;
    }
}
