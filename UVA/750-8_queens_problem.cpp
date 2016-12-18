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
int rows[8]={0},diags_maj[15]={0},diags_min[15]={0};
int x,y;
vector<int> ans;
int cnt=0;
vector<int> sols[8][8];
int pow_10[10];
void getans(int col,int res)
{
    if(col==8){ans.push_back(res);return;}
    for(int i=0;i<8;i++)
    {
        if(!rows[i] && !diags_maj[col-i+7] && !diags_min[i+col])
        {
            rows[i] = diags_maj[col-i+7] = diags_min[i+col] = 1;
            getans(col+1,res + (i+1)*pow_10[col]);
            rows[i] = diags_maj[col-i+7] = diags_min[i+col] = 0;
        }
    }
}
bool has(int n,int x)
{
    while(n)
    {
        if(x == n%10)
            return true;
        n/=10;
    }
    return n;
}
int main()
{
    pow_10[0] = 1;
    for(int i=1;i<10;i++)
        pow_10[i] = pow_10[i-1]*10;
    getans(0,0);
//    cout<<ans.size()<<endl;
//    cout<<ans[0]<<endl;
    in_T
    {
        in_I(x);in_I(y);
        int q = 0;
        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        for(int i=0;i<ans.size();i++)
        {
            if((ans[i]/pow_10[y-1])%10 == x)
            {
                q++;
                if(q/10 == 0)printf(" ");
                printf("%d     ",q);
                int n = ans[i];
                while(n)
                {
                    printf(" %d",n%10);
                    n/=10;
                }
                newline;
            }
        }
        if(t)
        newline;
    }
}
