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
char str[100010];
vector<int> neigh[11];
int chr2int[5][2] = {{0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}}, 
    int2chr[10] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
void addedge(int a, int b){
    neigh[a].push_back(b);
    neigh[b].push_back(a);
}
char res[100010];
int resCnt;
int dp[100010][2];
bool getans(int idx, int choice){
    int curNode = (idx == -1?10:chr2int[str[idx]-'A'][choice]);
    if(str[idx+1] == 0){
        return true;
    }
    if(idx >= 0)
    if(dp[idx][choice] != 2)
        return dp[idx][choice];
    for(int i = 0;i<neigh[curNode].size();i++){
        int v = neigh[curNode][i];
        int ch = int2chr[v]-'A';
        if(str[idx+1] == ch+'A'){
            bool ret;
            if(chr2int[ch][0] == v)
                ret = getans(idx+1, 0);
            else
                ret = getans(idx+1, 1);
            if(ret){
                res[resCnt++] = '0'+v;
                return true;
            }
        }
    }
    return (dp[idx][choice] =false);
}
int main()
{
    for(int i = 0;i<=4;i++)
        addedge(i, (i+1)%5), addedge(i, i+5);
    addedge(5, 7);
    addedge(5, 8);
    addedge(6, 8);
    addedge(6, 9);
    addedge(7, 9);
    for(int i = 0;i<10;i++)
        neigh[10].push_back(i);
    for(int i = 0;i<10;i++)
        sort(neigh[i].begin(), neigh[i].end());
    in_T{
        resCnt = 0;
        in_S(str);
        for(int i = 0;i<100010;i++)
            dp[i][0] = dp[i][1] = 2;
        if(!getans(-1, 0))
            printf("-1");
        else
        while(resCnt--){
            printf("%c", res[resCnt]);
        }
        newline;
    }
}
