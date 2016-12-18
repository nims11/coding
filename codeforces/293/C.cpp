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
int iconToPos[100003], posToIcon[100003];
int main()
{
    int n, m, k;
    in_I(n);in_I(m); in_I(k);
    int cur = -1;
    for(int i = 0;i<n;i++){
        if(i%k == 0)cur++;
        int x;
        in_I(x);
        iconToPos[x] = i;
        posToIcon[i] = x;
    }
    long long res = 0;
    for(int i = 0;i<m;i++){
        int x;
        in_I(x);
        res += iconToPos[x]/k+1;
        if(iconToPos[x] != 0){
            int prev = iconToPos[x] - 1;
            iconToPos[x] = prev;
            iconToPos[posToIcon[prev]]++;
            swap(posToIcon[prev], posToIcon[prev+1]);
        }
    }
    printf("%lld\n", res);
}
