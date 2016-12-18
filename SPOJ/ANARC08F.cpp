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
int N, C, R;
const int INF = 1e9;
int adj[100][100];
int cnt;
map<string, int> ids;
map<string, int>::iterator it1, it2;
char str1[13], str2[13], str[13];
vector<int> cars;
int main()
{
    int z = 0;
    while(1)
    {
        scanf("%d%d%d", &N, &C, &R);
        if(N==0)return 0;
        z++;
        cnt = 0;
        ids.clear();
        cars.clear();
        for(int i=0;i<=C;i++)
        {
            in_S(str1);
            it1 = ids.find(str1);
            if(it1 == ids.end())
            {
                ids[str1] = cnt++;
                cars.push_back(cnt-1);
            }else
                cars.push_back(it1->second);
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                adj[i][j] = INF;
            adj[i][i] = 0;
        }
        int x, i1, i2;
        for(int i=0;i<R;i++)
        {
            scanf("%s %c-%d-%c %s", str1, &str[0], &x, &str[1], str2);
            it1 = ids.find(str1);
            if(it1 == ids.end())
            {
                ids[str1] = cnt++;
                i1 = cnt-1;
            }else
                i1 = it1->second;
            it2 = ids.find(str2);
            if(it2 == ids.end())
            {
                ids[str2] = cnt++;
                i2 = cnt-1;
            }else
                i2 = it2->second;
            if(str[0] == '<')
                adj[i2][i1] = min(adj[i2][i1], x);
            if(str[1] == '>')
                adj[i1][i2] = min(adj[i1][i2], x);
        }
//        for(int i=0;i<N;i++, newline)
//            for(int j=0;j<N;j++)
//                cout<<adj[i][j]<<" ";

        for(int k=0;k<cnt;k++)
            for(int i=0;i<cnt;i++)
            for(int j=0;j<cnt;j++)
            adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
//        for(int i=0;i<N;i++, newline)
//            for(int j=0;j<N;j++)
//                cout<<adj[i][j]<<" ";
        int res = 0;
        for(int i=1;i<cars.size();i++)
        {
            res += adj[0][cars[i]] + adj[cars[i]][0];
        }
        printf("%d. %d\n", z, res);
    }
}
