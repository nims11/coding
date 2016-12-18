/*
    Nimesh Ghelani (nims11)
    Suffix Array + RMQ
    try all possible values of "l" to determine maximum k
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
#define MAX_STR_SIZE 50001
#define MAX_AUX 18
int ranks[200];
int LOG2[MAX_STR_SIZE];
class suffix_array
{
public:
    char str[MAX_STR_SIZE];
    struct node
    {
        int pos, tmp1, tmp2;
        friend bool operator<(const node &a, const node &b)
        {
            if(a.tmp1 == b.tmp1)
                return a.tmp2<b.tmp2;
            return a.tmp1<b.tmp1;
        }
    }nodes[MAX_STR_SIZE];
    int lcp_arr[MAX_STR_SIZE];
    int aux_lcp[MAX_STR_SIZE][MAX_AUX];
    int aux[MAX_AUX][MAX_STR_SIZE];
    int steps, cnt;
    int len;
    void create();
    void gen_lcp_arr();
    int lcp(int x, int y);
    int lcp_RMQ(int x, int y);
}S;
void suffix_array::create()
{
    len = 0;
    while(str[len])
    {
        aux[0][len] = ranks[str[len]];
        len++;
    }
    int pre = 0;
    cnt = 1;
    for(steps = 1;pre<len;steps++, cnt<<=1)
    {
        for(int i=0;i<len;i++)
        {
            nodes[i].pos = i;
            nodes[i].tmp1 = aux[steps-1][i];
            nodes[i].tmp2 = (i+cnt<len)?aux[steps-1][i+cnt]:-1;
        }
        sort(nodes, nodes+len);
        aux[steps][nodes[0].pos] = 0;
        for(int i=1;i<len;i++)
        {
            if(nodes[i].tmp1 == nodes[i-1].tmp1 && nodes[i].tmp2 == nodes[i-1].tmp2)
                aux[steps][nodes[i].pos] = aux[steps][nodes[i-1].pos];
            else
                aux[steps][nodes[i].pos] = i;
        }
        pre = cnt;
    }
}
int suffix_array::lcp(int x, int y)
{
    int ret = 0;
    if(x == y)return len-x;
    for(int k=steps-1;k>=0 && x<len && y<len; k--)
        if(aux[k][x] == aux[k][y]) x += 1<<k, y += 1<<k, ret += 1<<k;
    return ret;
}
void suffix_array::gen_lcp_arr()
{
    lcp_arr[0] = 0;
    for(int i=1;i<len;i++)
        lcp_arr[i] = lcp(nodes[i-1].pos, nodes[i].pos);

    for(int i=0;i<len;i++)
        aux_lcp[i][0] = lcp_arr[i];

    for(int j=1; 1<<j <= len; j++)
        for(int i=0; i+(1<<j)<=len; i++)
            aux_lcp[i][j] = min(aux_lcp[i][j-1], aux_lcp[i+(1<<(j-1))][j-1]);
}
int suffix_array::lcp_RMQ(int x, int y)
{
    x = aux[steps-1][x];
    y = aux[steps-1][y];
    if(x>y)
        swap(x, y);
    int k = LOG2[y-x];
    return min(aux_lcp[x+1][k], aux_lcp[y-(1<<k)+1][k]);
}
int main()
{
    int cnt = 0;
    for(char ch = 'a';ch<='b';ch++)
        ranks[ch] = cnt++;
    int x = 0;
    for(int i=0;i<MAX_STR_SIZE;i++)
    {
        if(1<<x <= i)
            x++;
        LOG2[i] = x-1;
    }
    int n;
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
            in_S(S.str+i);
        S.create();
        S.gen_lcp_arr();
        int res = 0;
        for(int l=1; l<=(n>>1); l++)
        {
            for(int i=0;i+l<n; i+=l)
            {
                int x = S.lcp_RMQ(i, i+l);
                if(x)
                {
                    int k = x/l;
                    x = i-(l-x%l);
                    if(x>=0 && S.lcp_RMQ(x, x+l)>=l)
                        k++;
                    if(i == 3 && l == 3)
                        cout<<k<<endl;
                    res = max(res, k);
                }
            }
        }
        printf("%d\n", res+1);
    }
}
