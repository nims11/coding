/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int grid[20][20];
int main()
{
    int N;
    in_I(N);
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            in_I(grid[i][j]);
}
