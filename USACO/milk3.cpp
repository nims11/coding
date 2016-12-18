/*
ID: nimeshg1
PROG: milk3
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
bool ans[21];
bool visited[21][21][21];
ifstream fin("milk3.in");
ofstream fout("milk3.out");
#define cin fin
#define cout fout
int A,B,C;
void getans(int a, int b, int c)
{
    if(a<0 || b<0 || c<0 || a>A || b>B || c>C || visited[a][b][c])
        return;
    visited[a][b][c] = 1;
    if(a == 0)
        ans[c] = true;
    getans(a-min(a, B-b), b+min(a, B-b), c);
    getans(a-min(a, C-c), b, c+min(a, C-c));

    getans(a+min(b, A-a), b-min(b, A-a), c);
    getans(a, b-min(b, C-c), c+min(b, C-c));

    getans(a+min(c, A-a), b, c-min(c, A-a));
    getans(a, b+min(c, B-b), c-min(c, B-b));
}
int main()
{
    cin>>A>>B>>C;
    getans(0,0,C);
    vector<int> res;
    for(int i=0;i<=C;i++)
        if(ans[i])
        res.push_back(i);

    for(int i=0;i<int(res.size())-1;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<res[res.size()-1]<<endl;
}
