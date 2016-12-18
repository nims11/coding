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
#define MAX_STR_SIZE 1001
#define MAX_AUX 12
int ranks[200];
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
    int aux[MAX_AUX][MAX_STR_SIZE];
    int steps, cnt;
    int len;
    void create();
    int lcp(int x, int y);
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
int main()
{
    int cnt = 0;
    for(char ch = 'A';ch<='Z';ch++)
        ranks[ch] = cnt++;
    in_T
    {
        in_S(S.str);
        S.create();
        int cur_lcp = 0;
        long long unsigned ans = S.len-S.nodes[0].pos;
//        cout<<S.str+S.nodes[0].pos<<endl;
        for(int i=1;i<S.len;i++)
        {
//            cout<<S.str+S.nodes[i].pos<<endl;
            cur_lcp = S.lcp(S.nodes[i-1].pos, S.nodes[i].pos);
//            cout<<cur_lcp<<endl;
            ans += S.len-S.nodes[i].pos-cur_lcp;
        }
        printf("%llu\n", ans);
    }
}
