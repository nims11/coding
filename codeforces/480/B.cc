#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;

const int mod = 1000000007;
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    char grid[4][n+1];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++)
            grid[i][j] = '.';
        grid[i][n] = 0;
    }

    int mid = n/2;
    if(k){
        grid[1][mid] = '#';
        k--;
    }
    int st = 1;
    while(k>1 && st + mid < n-1){
        grid[1][st+mid] = '#';
        grid[1][mid-st] = '#';
        st++;
        k -= 2;
    }

    if(k){
        if(k%2){
            grid[2][mid] = '#';
            k--;
        }
        st = 1;
        while(k>1 && st + mid < n-1){
            grid[2][st+mid] = '#';
            grid[2][mid-st] = '#';
            st++;
            k -= 2;
        }
    }

    if(k){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i = 0; i < 4; i++)
        cout<<grid[i]<<endl;
}
