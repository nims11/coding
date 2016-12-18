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
#include<cmath>
#include<stack>
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
string grid[50], tar_grid[50];
int n;
struct ans_node{
    int x1,x2,y1,y2,op;
    ans_node(int x11,int y11,int x21, int y21, int op1):x1(x11),x2(x21),y1(y11),y2(y21),op(op1){}
};
char opcode[] = {'W', 'B', 'F'};
vector<ans_node> ans;
void getans(int x1, int y1, int x2, int y2)
{
    if(x2<x1 || y2<y1)
        return;
//    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    if(x1 == x2 && y1 == y2)
    {
        if(tar_grid[x1][y1] == 'W' && grid[x1][y1] == 'B')
        {
            ans.push_back(ans_node(x1,y1,x2,y2,0));
            grid[x1][y1] = 'W';
        }else if(tar_grid[x1][y1] == 'B' && grid[x1][y1] == 'W')
        {
            ans.push_back(ans_node(x1,y1,x2,y2,1));
            grid[x1][y1] = 'B';
        }
        return;
    }
    int flip = 0;
    int w_b = 0;
    int b_w = 0;
    int b_b = 0;
    int w_w = 0;
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
        {
            if(grid[i][j] != tar_grid[i][j])
            {
                flip++;
            }
            w_b += (grid[i][j] == 'W' && tar_grid[i][j] == 'B');
            b_w += (grid[i][j] == 'B' && tar_grid[i][j] == 'W');
            w_w += (grid[i][j] == 'W' && tar_grid[i][j] == 'W');
            b_b += (grid[i][j] == 'B' && tar_grid[i][j] == 'B');
        }
    }
    int total = w_w+b_b;
    int candi1,candi2,candi3;
    // flipping
    candi1 = flip;
    // B
    candi2 = b_b + w_b;
    //W
    candi3 = w_w + b_w;
    int maxi = max(max(total, candi1), max(candi2, candi3));
    if(maxi == total)
    {

    }else if(maxi == candi1)
    {
        ans.push_back(ans_node(x1,y1,x2,y2,2));
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
            if(grid[i][j] == 'B')grid[i][j] = 'W';
            else                   grid[i][j] = 'B';
    }else if(maxi == candi2)
    {
        ans.push_back(ans_node(x1,y1,x2,y2,1));
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
            grid[i][j] = 'B';
    }
    else
    {
        ans.push_back(ans_node(x1,y1,x2,y2,0));
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
            grid[i][j] = 'W';
    }
    if(x2-x1>y2-y1)
    {
        getans(x1,y1,(x1+x2)/2,y2);
        getans((x1+x2)/2+1,y1,x2,y2);
    }else
    {
        getans(x1,y1,x2,(y1+y2)/2);
        getans(x1,(y1+y2)/2+1,x2,y2);
    }
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
        cin>>tar_grid[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            grid[i].push_back('W');
    getans(0,0,n-1,n-1);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].x1<<" "<<ans[i].y1<<" "<<ans[i].x2<<" "<<ans[i].y2<<" "<<opcode[ans[i].op]<<endl;
    }
//    for(int i=0;i<n;i++)
//        cout<<grid[i]<<endl;
//    cout<<endl;
}
