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
int N, M;
int adj[100][100];
int dV[100];
int main()
{
    in_T{
        in_I(N);
        in_I(M);
        int x,y;
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                if(i != j)
                    adj[i][j] = 1e9;

        for(int i = 0;i<M;i++){
            in_I(x);in_I(y);
            x--, y--;
            adj[x][y] = adj[y][x] = 1;
        }
        for(int k = 0;k<N;k++)
            for(int i = 0;i<N;i++)
                for(int j = 0;j<N;j++)
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
        for(int i = 0;i<N;i++){
            dV[i] = 0;
            for(int j = 0;j<N;j++)
                dV[i] = max(dV[i], adj[i][j]);
        }
        int mini = dV[0], maxi = dV[0];
        for(int i = 0;i<N;i++)
            mini = min(dV[i], mini), maxi = max(dV[i], maxi);
        // cout<<mini<<" "<<maxi<<endl;
        if(mini == maxi){
            printf("0 0\n");
        }else{
            int remN = 2*N;
            int remM = N*(N-1);
            if(N >= 4){
                printf("%d %d\n", 4, 2*N+2);
                printf("%d %d\n%d %d\n",N+1,N+3,N+2,N+4);
                for(int i = 0;i<N;i++)
                    printf("%d %d\n%d %d\n", i+1, N+1, i+1, N+2);
            }else if(N == 3){
                printf("2 3\n");
                for(int i = 0;i<N;i++){
                    if(dV[i] == 2)
                        printf("%d %d\n", i+1, N+1);
                    else if(dV[i] == 1)
                        printf("%d %d\n", i+1, N+2);
                }
            }else{
                printf("-1 -1\n");
            }
        }
    }
}
