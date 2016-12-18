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
int arr[100001];
int visited[100001][2];
int foo[100001];
int main()
{
    in_T{
        int n, m;
        in_I(n);in_I(m);
        for(int i = 0;i<n;i++)
            in_I(arr[i+1]), foo[i+1] = 0, visited[i][0] = visited[i][1] =0;
        for(int i = 0;i<m;i++){
            int x, y;
            in_I(x);in_I(y);
            visited[x][0]++;
            visited[y][1]++;
        }
        int cnt = 0;
        int cur = 0;
        for(int i = 1;i<=n;i++){
            cur += visited[i][0];
                foo[i] = cnt;
            cur -= visited[i][1];
            if(cur == 0)
                cnt++;
        }
        bool flag = true;
        for(int i = 1;i<=n;i++){
            if(foo[i] != foo[arr[i]])
                flag = false;
        }
        cout<<(flag?"Possible":"Impossible")<<endl;
    }
}
