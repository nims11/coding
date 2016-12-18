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
#define BE(a) a.begin(), a.end()

using namespace std;
set<int> openKingdoms;
int main()
{
    in_T{
        int N;
        in_I(N);
        openKingdoms.clear();
        vector<int> kings[2001][2];
        int x, y;
        for(int i = 0;i<N;i++){
            in_I(x);in_I(y);
            kings[x][0].push_back(i);
            kings[y][1].push_back(i);
        }
        int ans = 0;
        for(int i = 0;i<=2000;i++){
            for(int a:kings[i][0])
                openKingdoms.insert(a);
            for(int b:kings[i][1]){
                if(openKingdoms.find(b) != openKingdoms.end()){
                    ans++;
                    openKingdoms.clear();
                }
            }
        }
        printf("%d\n", ans);
    }
}
