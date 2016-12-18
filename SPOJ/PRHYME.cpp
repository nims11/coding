/*
    Nimesh Ghelani (nims11)
    For dictionary, store them as trie of the reverse of the strings.
    Also store two lexicographically smallest strings which can be formed by following that node.
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
    int id;
    int min1, min2;
    node* kids[26];
    void init()
    {
        status = 0;
        for(int i=0;i<26;i++)
            kids[i] = 0;
        min1 = min2 = -1;
        id = -2;
    }
}nodes[1000000];
int cnt = 0;
char L[250000][31];
char str[31];
int L_cnt = 0;
int L_id;
void insert(node *curr, int idx)
{
    if(idx == -1)
    {
        curr->status = 1;
        curr->id = L_cnt;
    }else
    if(curr->kids[L[L_cnt][idx]-'a'])
    {
        insert(curr->kids[L[L_cnt][idx]-'a'], idx-1);
    }else
    {
        if(curr->status == 0)
            curr->status = 2;
        nodes[cnt].init();
        curr->kids[L[L_cnt][idx]-'a'] = &nodes[cnt];
        cnt++;
        insert(curr->kids[L[L_cnt][idx]-'a'], idx-1);
    }
    if(curr->min1 == -1)
        curr->min1 = L_cnt;
    else if(strcmp(L[L_cnt], L[curr->min1])<0)
    {
        curr->min2 = curr->min1;
        curr->min1 = L_cnt;
    }else if(curr->min2 == -1)
        curr->min2 = L_cnt;
    else if(strcmp(L[L_cnt], L[curr->min2])<0)
    {
        curr->min2 = L_cnt;
    }
}
bool findSuff(node* curr, int idx)
{
    if(idx == -1)
    {
        if(curr->min1 == -1)
            return false;
        if(curr->min1 != curr->id)
        {
            printf("%s\n", L[curr->min1]);
            return true;
        }
        if(curr->min2 == -1)
            return false;
        if(curr->min2 != curr->id)
        {
            printf("%s\n", L[curr->min2]);
            return true;
        }
        return false;
    }
    if(curr->kids[str[idx]-'a'])
    {
        if(findSuff(curr->kids[str[idx]-'a'], idx-1))
            return true;
    }
    if(curr->min1 == -1)
        return false;
    if(curr->min1 != curr->kids[str[idx]-'a']->min1 && curr->min1 != curr->kids[str[idx]-'a']->min2)
    {
        printf("%s\n", L[curr->min1]);
        return true;
    }
    if(curr->min2 == -1)
        return false;
    if(curr->min2 != curr->kids[str[idx]-'a']->min1 && curr->min2 != curr->kids[str[idx]-'a']->min2)
    {
        printf("%s\n", L[curr->min2]);
        return true;
    }
    return false;
}
int main()
{
    cnt = 1;
    nodes[0].init();

    while(1)
    {
        gets(L[L_cnt]);
        if(L[L_cnt][0] == 0)
            break;
        insert(&nodes[0], strlen(L[L_cnt])-1);
        L_cnt++;
    }
    while(gets(str) != NULL)
    {
        findSuff(&nodes[0], strlen(str)-1);
        if(str[0] == 0)
            break;
    }
}
