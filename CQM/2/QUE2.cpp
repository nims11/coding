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
struct node
{
    node* left, *right;
    int size;
}nodes[10005];
int n;
pair<int, int> arr[10005];
node* root;
vector<int> ans;
void pre(node* id)
{
    if(id == 0)
        return;
    pre(id->left);
    ans.push_back(arr[int(id-nodes)].first);
    pre(id->right);
}
int ins(node *r, node *curr, int rank)
{
//    cout<<(r-nodes)<<" "<<curr-nodes<<" "<<rank<<endl;
//    int x;
//    cin>>x;
    if(root == 0)
    {
        root = curr;
        return 1;
    }
    if(r == 0)
    {
        cout<<"As"<<endl;
        return 1;
    }
    if(rank == 0 && r->left == 0)
    {
        r->left = curr;
    }else if( (r->left?r->left->size:0)+1 == rank && r->right == 0)
    {
        r->right = curr;
    }else
    if(rank > (r->left?r->left->size:0))
    {
        if(r->right)
            ins(r->right, curr, rank-(r->left?r->left->size:0)-1);
        else
            ins(r->left, curr, rank);
    }else
    {
        ins(r->left, curr, rank);
    }
    r->size = (r->left?r->left->size:0) + (r->right?r->right->size:0) + 1;
    return r->size;
}
int main()
{
    nodes[0].size = 0;
    arr[0].first = -1;
    in_T
    {
        in_I(n);
        root = 0;
        for(int i = 1; i<=n; i++)
        {
            in_I(arr[i].first);
            nodes[i].left = nodes[i].right = 0;
            nodes[i].size = 1;
        }
        for(int i = 1; i<=n; i++)
        {
            in_I(arr[i].second);
        }
        ans.clear();
        sort(arr+1, arr+n+1);
        for(int i = n; i>=1; i--)
        {
//            cout<<i<<endl;
            assert(arr[i].first != arr[i-1].first);
            ins(root, &nodes[i], arr[i].second);
        }
        pre(root);
        for(int i = 0; i<ans.size(); i++)
            cout<<ans[i]<<(ans.size()-1 == i? "":" ");
        cout<<endl;
    }
}
