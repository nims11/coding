/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
#define MAX_STR_SIZE 51000
#define MAX_AUX 18
class suffix_array
{
public:
    char str[MAX_STR_SIZE];
    struct node
    {
        int pos, tmp1, tmp2;
        char *ptr;
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
    static bool cmp_worst(const node &a, const node &b)
    {
        return strcmp(a.ptr, b.ptr) < 0;
    }
    static int cmp_worstq(const void *a, const void *b)
    {
        const node **ia = (const node **)a;
        const node **ib = (const node **)b;
        cout<<(*ia)->ptr<<endl;
        return strcmp((*ia)->ptr, (*ib)->ptr);
    }
    void create();
    void create_worst();
}S;
void suffix_array::create()
{
    len = 0;
    while(str[len])
    {
        aux[0][len] = str[len]-'A';
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
void suffix_array::create_worst()
{
    len = 0;
    while(str[len])
    {
        nodes[len].ptr = str+len, nodes[len].pos = len;
        len++;
    }
    qsort(nodes, len, sizeof(node*), cmp_worstq);
}
int main()
{
    in_T
    {
        in_S(S.str);
        S.create_worst();
        long long unsigned ans=S.len-S.nodes[0].pos;
        for(int i=1;i<S.len;i++)
        {
            int suff_len1=S.len-S.nodes[i].pos;
            int suff_len2=S.len-S.nodes[i-1].pos;

            int j;int lt=MIN(suff_len1,suff_len2);
            for(j=0;j<lt;j++)
            {
                if(S.str[S.len-suff_len1+j]!=S.str[S.len-suff_len2+j])
                break;
            }
            ans+=suff_len1-j;
        }
        printf("%llu\n", ans);
    }
}

