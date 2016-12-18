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
#define TEST(r, c) ((r)>=0 && (r)<n && (c)>=0 && (c)<m && A[r][c] == '1')

using namespace std;
int n,m;
set<pair<int, int> >M;
set<pair<int, int> >::iterator it;
char A[102][102];
const int INF = 1e9;
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
pair<int, int> path[101][101];
int brute(int r, int c, set<pair<int, int> > M = set<pair<int, int> >())
{
    if(r == n || c == m)
        return INF;
    for(int i=0;i<5;i++)
    {
        int rr = r+dx[i], cc = c+dy[i];
        if(TEST(rr, cc))
            M.insert(make_pair(rr, cc));
    }
    if(r == n-1 && c == m-1)
        return M.size();
    int A = brute(r+1, c, M);
    int B = brute(r, c+1, M);
    if(A<B)
    {
        path[r][c] = make_pair(r+1, c);
    }else
        path[r][c] = make_pair(r, c+1);
    return min(A, B);
}
int main()
{
    in_T
    {
        in_I(n);
        in_I(m);
        for(int i=0;i<n;i++)
        {
            in_S(A[i]);
//            cout<<A[i]<<endl;
        }
        cout<<brute(0, 0)<<endl;
        int i = 0, j = 0;
    }
}
