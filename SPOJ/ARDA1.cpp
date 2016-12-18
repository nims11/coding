/*
Nimesh Ghelani (nims11)
Hashing
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
int N1, N2, M1, M2;
const int d = 203;
int main()
{
    scanf("%d%d", &N1, &N2);
    char P[N1][N2+1];
    for(int i = 0; i<N1; i++)
        in_S(P[i]);

    scanf("%d%d", &M1, &M2);
    char S[M1][M2+1];
    for(int i = 0; i<M1; i++)
        in_S(S[i]);

    int unsigned hash_p = 0;
    for(int i = 0; i < N2; i++)
        for(int j = 0; j < N1; j++)
            hash_p = hash_p*d + P[j][i];
    int unsigned hash_vert[M1-N1+1][M2];
    int unsigned pow1 = 1, pow2 = 1, pow3 = 1;
    for(int i = 0; i<N1-1; i++)
        pow3 *= d;
    pow1 = d*pow3;
    for(int i = 0; i<(N2-1)*N1; i++)
        pow2 *= d;

    for(int j = 0; j<M2; j++)
    {
        hash_vert[0][j] = 0;
        for(int i = 0; i<N1; i++)
            hash_vert[0][j] = hash_vert[0][j]*d + S[i][j];
//        cout<<hash_vert[0][j]<<" ";
        for(int i = 1; i<M1-N1+1; i++)
        {
            hash_vert[i][j] = hash_vert[i-1][j] - pow3*(S[i-1][j]);
            hash_vert[i][j] = hash_vert[i][j]*d + (S[i+N1-1][j]);
//            cout<<hash_vert[i][j]<<" ";
        }
//        newline;
    }
    bool res=  false;
    for(int i = 0; i < M1 - N1 + 1; i++)
    {
        int unsigned hash_curr = 0;
        for(int j = 0; j < N2; j++)
            hash_curr = hash_curr*pow1 + hash_vert[i][j];
//        cout<<hash_curr<<" ";
        if(hash_curr == hash_p)
            res = true, printf("(%d,%d)\n", i+1, 1);
        for(int j = 1; j < M2 - N2 + 1; j++)
        {
            hash_curr -= hash_vert[i][j-1]*pow2;
            hash_curr = hash_curr*pow1 + hash_vert[i][j+N2-1];
//            cout<<hash_curr<<" ";
            if(hash_curr == hash_p)
                res = true, printf("(%d,%d)\n", i+1, j+1);
        }
//        newline;
    }
    if(!res)
    {
        printf("NO MATCH FOUND...\n");
    }
}



