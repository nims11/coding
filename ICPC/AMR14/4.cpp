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
int N, M;
int W[101][101];
long long getans(int x1, int y1, int x2, int y2){
    int xx1 = x1, yy1 = y2,  xx2 = x2, yy2 = y1;
    long long ret = 0;
    for(int i = x1, j = y1, i1 = xx1, j1 = yy1;i<=x2 && j<=y2;i++, j++, i1++, j1--){
            ret += W[i][j];
            ret += W[i1][j1];
    }
//    if(x1 == 0 && y1 == 0 && x2 == 1 && y2 == 1)
//        cout<<xx1<<" "<<yy1<<" "<<xx2<<" "<<yy2<<endl;
    if((x1+x2)%2 == 0 && (y1+y2)%2 == 0)
        ret -= W[(x1+x2)/2][(y1+y2)/2];
    return ret;
}
int main()
{
    in_T{
        in_I(N);
        in_I(M);
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++)
                in_I(W[i][j]);
        long long res = -1e15;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                for(int k = 1;i+k<N && j+k<M;k++)
                    res = max(res, getans(i, j, i+k, j+k));
            }
        }
        printf("%lld\n", res);
    }
}
