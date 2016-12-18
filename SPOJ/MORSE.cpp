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
int rank[200];
struct node
{
    int status; // 0 - new 1 - end 2 - not_end
    node *kids[2];
    int nums;
    static int cnt;
    static node* get();
}nodes[1000005];
int node::cnt = 0;
node* node::get()
{
    assert(cnt<1000005);
    nodes[cnt].status = 0;
    nodes[cnt].nums = 0;
    for(int i=0;i<2;i++)
        nodes[cnt].kids[i] = 0;
    return (nodes+(cnt++));
}
char str[100];
void insert_trie(node *curr, int idx)
{
    if(!str[idx])
    {
        curr->status = 1;
        curr->nums++;
        return;
    }
    if(!curr->kids[rank[str[idx]]])
    {
        if(curr->status == 0)
            curr->status = 2;
        curr->kids[rank[str[idx]]] = node::get();
    }
    insert_trie(curr->kids[rank[str[idx]]], idx+1);
}

char morse[10003];
int n;
char tmp[25];
char mapp[26][10] = {
                   ".-", "-...", "-.-.", "-..",
                   ".", "..-.", "--.", "....",
                   "..", ".---", "-.-", ".-..",
                   "--", "-.", "---", ".--.",
                   "--.-", ".-.", "...", "-",
                   "..-", "...-", ".--", "-..-",
                   "-.--", "--.."
};
vector<int> dplen[10003];
int dp[10003];
node * trie;
int cur_i;
void dfs(node *curr, int cnt, int idx)
{
    if(curr->status == 1)
    {
        for(int i=0;i<curr->nums;i++)
        dplen[cur_i].push_back(cnt);
    }
    if(!morse[idx] || curr->kids[rank[morse[idx]]] == 0)
        return;
    dfs(curr->kids[rank[morse[idx]]], cnt+1, idx+1);
}
int main()
{
    rank['.'] = 0;
    rank['-'] = 1;
    in_T
    {
        node::cnt = 0;
        trie = node::get();
        in_S(morse);
        int len = 0;
        for(;morse[len];len++)
            dplen[len].clear();
        in_I(n);
        while(n--)
        {
            in_S(tmp);
            int c = 0;
            for(int i=0;tmp[i];i++)
            {
                for(int j=0;mapp[tmp[i]-'A'][j];j++)
                {
                    str[c++] = mapp[tmp[i]-'A'][j];
                }
            }
            str[c] = 0;
            insert_trie(trie, 0);
        }
        for(int i=0;i<len;i++)
        {
            cur_i=i;
            dfs(trie, 0, i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=1;i<=len;i++)
        {
//            cout<<i<<endl;
            for(int j=0;j<dplen[i-1].size();j++)
            {
//                cout<<" "<<dplen[i-1][j];
                dp[i+dplen[i-1][j]-1] += dp[i-1];
            }
//            cout<<endl;
        }
//        for(int i=0;i<=len;i++)
//            cout<<dp[i]<<" ";
//        cout<<endl;
        printf("%d\n", dp[len]);
        if(t)
            newline;
    }
}


