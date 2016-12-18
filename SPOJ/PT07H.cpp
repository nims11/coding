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
#include<cassert>
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
    node *par;
    int id;
    map<unsigned int, node *> kids;
}nodes[10000];
node* root = &nodes[0];
int type; //0 -> start, 1 -> end
unsigned int H;
char str[1000000];
int rank[200];
const int d = 52;
int cnt = 1;
int id_cnt = 1;
map<unsigned int, vector<node*> > appear;
map<unsigned int, string> repr;
node* create()
{
    int curr = 0;
    unsigned int first = 0;
    bool flag_first = true;
    fread(str, 1, 999999, stdin);
    int status = 0;
    // 0 -> nothing
    // 1 -> entry tag opened
    // 2 -> closed tag opened
    int i = 0;
    string foo;
    unsigned int H = 0;
    node* curr_node = &nodes[0];
    node* patt = &nodes[cnt++];
    patt->par = 0;
    int pos = 0;
    // 0 -> main
    // 1 -> pattern
    while(str[i])
    {
        if(str[i] == '<')
        {
            assert(status == 0);
            if(str[i+1] == '/')
            {
                status = 2;
                i++;
            }else
                status = 1;
        }else if(str[i] == '>')
        {
            assert(status != 0);
//            cout<<status<<" "<<foo<<endl;
            if(status == 1)
            {
//                assert(curr_node->kids.count(H) == 0);
                curr_node->kids[H] = &nodes[cnt];
                nodes[cnt].par = curr_node;
                curr_node = &nodes[cnt++];
                curr_node->id = id_cnt++;
                if(!pos)
                    appear[H].push_back(curr_node);
                repr[H] = foo;
            }else if(status == 2)
            {
//                assert()
                curr_node = curr_node->par;
                if(H == first && curr_node->par == 0)
                {
                    pos = 1;
                    curr_node = patt;
                }
            }else
            {
                exit(1);
            }
            if(flag_first)
            {
                first = H;
                flag_first = false;
            }
            status = 0;
            H = 0;
            foo = "";
        }else if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') && status != 0)
        {
            assert(status != 0);
            H = H*d + rank[str[i]];
            foo.push_back(str[i]);
        }
        i++;
    }
    return patt;
}
map<unsigned int, node*>::iterator it, it2;
bool match(node *A, node *B)
{
    for(map<unsigned int, node*>::iterator it = B->kids.begin(); it != B->kids.end(); it++)
    {
        unsigned int H = it->first;
        it2 = A->kids.find(H);
        if(it2 != A->kids.end())
        {
            if(!match(it2->second, it->second))
                return false;
        }else
            return false;
    }
    return true;
}
void BFS(node* root)
{
    queue<node*> X;
    X.push(root);
    while(!X.empty())
    {
        node *tmp = X.front();
        X.pop();
        for(it = tmp->kids.begin(); it!=tmp->kids.end(); it++)
        {
            cout<<repr[it->first]<<endl;
            X.push(it->second);
        }
    }
}
int main()
{
    int cnt = 0;
    for(char ch='A';ch!='Z';ch++)
        rank[ch] = cnt++;
    for(char ch='a';ch!='z';ch++)
        rank[ch] = cnt++;
    nodes[0].par = 0;
    nodes[0].id = 0;
    node* patt = create();
    unsigned int first = patt->kids.begin()->first;
    vector<node*> &x = appear.find(first)->second;
    vector<int> ans;
    for(int i=0;i<x.size();i++)
    {
        if(match(x[i]->par, patt))
            ans.push_back(x[i]->id);
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++)
        printf("%d\n", ans[i]);
}
