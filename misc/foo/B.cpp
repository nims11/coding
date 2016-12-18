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
int rowSum[1000];
int colSum[1000];
int main()
{
    int n, m, k, p;
    in_I(n);in_I(m);
    in_I(k);in_I(p);
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
            int tmp;
            in_I(tmp);
            rowSum[i] += tmp;
            colSum[j] += tmp;
        }
    int rowNeg = 0, colNeg = 0;
    multiset<long long> row, col;
    for(int i = 0;i<n;i++)
        row.insert(rowSum[i]);
    for(int i = 0;i<m;i++)
        col.insert(colSum[i]);
    multiset<long long>::iterator it_r, it_c;
    long long topRowSum[k+1], topColSum[k+1];
    topColSum[0] = 0, topRowSum[0] = 0;
    for(int i = 1;i<=k;i++){
        it_r = row.end();
        --it_r;
        topRowSum[i] = topRowSum[i-1] + *it_r;
        long long tmp = *it_r;
        row.erase(it_r);
        row.insert(tmp - m*p);
    }
    for(int i = 1;i<=k;i++){
        it_c = col.end();
        --it_c;
        topColSum[i] = topColSum[i-1] + *it_c;
        long long tmp = *it_c;
        col.erase(it_c);
        col.insert(tmp - n*p);
    }
    long long res = 0;
    for(int i = 0;i<=k;i++){
        res = max(res, topRowSum[i] + topColSum[k-i] - p*1LL*i*(k-i));
    }

    cout<<res<<endl;
}
