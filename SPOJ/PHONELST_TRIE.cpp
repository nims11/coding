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
    node* kids[10];
}nodes[1000000];
int cnt = 0;
int n;
char str[12];
bool insert(node *curr, int idx)
{
    if(!str[idx])
    {
        if(curr->status == 0)
        {
            curr->status = 1;
            return true;
        }else
            return false;
    }
    if(curr->kids[str[idx]-'0'])
    {
        return insert(curr->kids[str[idx]-'0'], idx+1);
    }else
    {
        if(curr->status == 1)
        {
            return false;
        }else
        {
            if(curr->status == 0)
                curr->status = 2;
            for(int i=0;i<10;i++)
                nodes[cnt].kids[i] = 0, nodes[cnt].status = 0;
            curr->kids[str[idx]-'0'] = &nodes[cnt];
            cnt++;
            return insert(curr->kids[str[idx]-'0'], idx+1);
        }
    }
}
int main()
{
    in_T
    {
        cnt = 1;
        for(int i=0;i<10;i++)
            nodes[0].kids[i] = 0, nodes[0].status = 0;
        in_I(n);
        bool flag = true;
        while(n--)
        {
            in_S(str);
            if(flag)
            {
                flag = insert(&nodes[0], 0);
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
