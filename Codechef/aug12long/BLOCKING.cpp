/*
    Nimesh Ghelani (nims11)
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
struct foo
{
    int T,H;
    friend bool operator<(const foo &a,const foo &b)
    {
        return a.T<b.T;
    }
}bar[100][100];
int n;
int visited[101];
bool getans(int N)
{
    if(N==-1)return true;
    int i=0;
    while(i<n && (visited[bar[N][i].H]>bar[N][i].T || visited[bar[N][i].H]==-1))
    {
        i++;
    }
    P_I(i);newline;
    for(i=i-1;i>=0;i--)
    {
        if(visited[bar[N][i].H]==-1)
        {
            visited[bar[N][i].H]=bar[N][i].T;
            if(getans(N-1)){printf("%d ",bar[N][i].H+1);return true;}
            visited[bar[N][i].H]=-1;
        }
    }
    return false;
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)visited[i]=-1;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        in_I(bar[i][j].T);
        bar[i][j].H=j;
    }

    for(int i=0;i<n;i++)
    sort(bar[i],bar[i]+n);

//    for(int i=0;i<n;i++)
//    {for(int j=0;j<n;j++)
//    cout<<bar[i][j].T<<","<<bar[i][j].H<<" ";
//    cout<<endl;}

    if(!getans(n-1))
    printf("-1\n");
}
