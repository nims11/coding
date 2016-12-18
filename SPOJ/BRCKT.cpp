//GQ
/*
    Nimesh Ghelani (nims11)
    Binary division of the string. For each node corresponding a range, store the number of open brackets required in left
    and number of closed brackets required in right.
    Update the Tree when required.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
struct bar
{
    int l,r;
};
bar TREE[1000000];
int n,modify_index;char str[30002];
void build_tree(int NODE,int a,int b)
{
    if(a==b)
    {
        if(str[a]=='(')TREE[NODE].l=0,TREE[NODE].r=1;
        else TREE[NODE].l=1,TREE[NODE].r=0;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_tree(left,a,mid);
    build_tree(right,mid+1,b);
    TREE[NODE].l=TREE[left].l;
    TREE[NODE].r=TREE[right].r;
    int k=TREE[left].r-TREE[right].l;
    if(k>0)TREE[NODE].r+=k;
    else TREE[NODE].l-=k;
}
void update_tree(int NODE,int a,int b)
{
    if(a==b)
    {
        if(str[a]=='(')TREE[NODE].l=0,TREE[NODE].r=1;
        else TREE[NODE].l=1,TREE[NODE].r=0;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;

    if(mid>=modify_index)
    update_tree(left,a,mid);
    else
    update_tree(right,mid+1,b);

    TREE[NODE].l=TREE[left].l;
    TREE[NODE].r=TREE[right].r;
    int k=TREE[left].r-TREE[right].l;
    if(k>0)TREE[NODE].r+=k;
    else TREE[NODE].l-=k;
}
int main()
{
    int q;
    for(int i=1;i<=10;i++)
    {
        in_I(n);
        in_S(str);
        build_tree(1,0,n-1);

        in_I(q);
        printf("Test %d:\n",i);

        while(q--)
        {
            in_I(modify_index);
            if(modify_index==0)
            {
                if(TREE[1].l==0 && TREE[1].r==0)cout<<"YES\n";
                else cout<<"NO\n";
            }else
            {
                modify_index--;
                str[modify_index]=(str[modify_index]=='(')?')':'(';
                update_tree(1,0,n-1);
            }
        }
    }
}
