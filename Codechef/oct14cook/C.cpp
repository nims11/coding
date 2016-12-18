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
int n;
int arr[1<<16];
int tmp[1<<16];
int sub = 0;
vector<int> res;
void solve(int N){
    tmp[0] = 0;
    int tmpSz = 1;
    priority_queue<int> foo;
    for(int i = 1;i<(1<<N);i++){
        if(foo.empty() || foo.top() != -arr[i]){
            res.push_back(arr[i]);
            int tmpSz2 = tmpSz;
            for(int j = 0;j<tmpSz;j++){
                tmp[tmpSz2++] = tmp[j]+arr[i];
                if(j > 0)
                foo.push(-tmp[j]-arr[i]);
            }
            tmpSz = tmpSz2;
        }else
            foo.pop();
    }
}
int main()
{
    in_T{
        in_I(n);
        res.clear();
        for(int i = 0;i<(1<<n);i++)
            in_I(arr[i]);
        sub = 0;
        sort(arr, arr+(1<<n));
        solve(n);
        for(int i = 0;i<res.size();i++)
            printf("%d ", res[i]);
        newline;
    }
}
