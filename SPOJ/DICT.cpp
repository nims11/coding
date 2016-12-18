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
struct node
{
    // 0 - new
    // 1 - end
    // 2 - not end
    int status;
    node* kids[26];
}nodes[1000000];
int cnt = 0;
int n;
char str[23];
void insert(node *curr, int idx)
{
    if(!str[idx])
    {
        curr->status = 1;
        return;
    }
    if(curr->kids[str[idx]-'a'])
    {
        insert(curr->kids[str[idx]-'a'], idx+1);
    }else
    {
        if(curr->status == 0)
            curr->status = 2;
        for(int i=0;i<26;i++)
            nodes[cnt].kids[i] = 0, nodes[cnt].status = 0;
        curr->kids[str[idx]-'a'] = &nodes[cnt];
        cnt++;
        insert(curr->kids[str[idx]-'a'], idx+1);
    }
}
bool flag;
char str2[30];
int tmp;
void print(node *curr)
{
    if(curr->status == 1 && str2[0])
    {
        flag = true;
        printf("%s%s\n", str, str2);
    }
    for(int i=0;i<26;i++)
    {
        if(curr->kids[i])
        {
            str2[tmp++] = 'a'+i;
            str2[tmp] = 0;
            print(curr->kids[i]);
            str2[--tmp] = 0;
        }
    }
}
void find_trie(node* curr, int idx)
{
    if(!str[idx])
    {
        str2[0] = 0;
        tmp = 0;
        print(curr);
        return;
    }
    if(curr->kids[str[idx]-'a'])
        find_trie(curr->kids[str[idx]-'a'], idx+1);
}
int main()
{
    cnt = 1;
    nodes[0].status = 0;
    for(int i=0;i<26;i++)
        nodes[0].kids[i] = 0;
    in_I(n);
    while(n--)
    {
        in_S(str);
        insert(&nodes[0], 0);
    }
    in_I(n);
    for(int i=1;i<=n;i++)
    {
        printf("Case #%d:\n", i);
        flag = false;
        in_S(str);
        find_trie(&nodes[0], 0);
        if(!flag)
            printf("No match.\n");
    }
}
