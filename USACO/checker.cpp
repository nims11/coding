/*
ID: nimeshg1
PROG: checker
LANG: C++
*/
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
#include<set>
#include<utility>
#include<fstream>
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
ifstream fin("checker.in");
ofstream fout("checker.out");
#define cin fin
#define cout fout
int n;
int solns = 0;
int tot = 0;
vector<int> soln;
void dfs(int r, int cols, int diag1, int diag2)
{
    if(r == n)
    {
        if(tot<3){
        for(int i=0;i<-1+(int)soln.size();i++)
            cout<<soln[i]<<" ";
        cout<<soln[soln.size()-1]<<endl;
        }
        tot++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!(cols & (1<<i)) && !(diag1 & (1<<(i+r))) && !(diag2 & (1<<(i-r+n))) )
        {
            soln.push_back(i+1);
            dfs(r+1, cols|(1<<i), diag1|(1<<(i+r)), diag2|(1<<(i-r+n)));
            soln.pop_back();
        }
    }
}
int main()
{
    cin>>n;
    dfs(0,0,0,0);
    cout<<tot<<endl;
}
