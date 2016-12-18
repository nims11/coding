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
int n, k;
int arr[34];
double p[201][31][31];
void compute(){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++){
            int x1 = min(i, j);
            int x2 = max(i, j);
            p[1][i][j] = min(x1+1, n-x2)/(double)(n*(n+1)/2);
        }
    for(int z = 2;z<=k;z++){
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++){
                for(int x = 0;x<n;x++){
                    p[z][i][j] += p[z-1][i][x]*p[1][x][j];
                }
            }
    }
}
int main()
{
    cin>>n>>k;
    int x;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
            compute();
    long double res = 0;
    for(int i = 0;i<n;i++)
        for(int j = i+1;j<n;j++){
            for(int x = 0;x<n;x++){
                for(int l = x+1;l<n;l++){
                    if(arr[i] < arr[j])
                        res += p[k][i][l] * p[k][j][x];
                    else
                        res += p[k][i][x] * p[k][j][l];
                }
            }
        }
    cout<<fixed;
    cout<<setprecision(10)<<res<<endl;;
}
