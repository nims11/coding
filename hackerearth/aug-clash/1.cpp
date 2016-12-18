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
int x[10] = {-1, -1, 0, 1, -1, 2, -1, 3, -1, -1};
long long cnt[16];
int main()
{
    int n;
    long long L;
    in_I(n);
    for(int i = 0;i<n;i++){
        in_L(L);
        int mask = 0;
        while(L){
            int y = L%10;
            L/=10;
            if(x[y] != -1)
            mask |= (1<<x[y]);
        }
        cnt[mask]++;
    }
    long long ans = 0;
    for(int i = 0;i<16;i++){
        for(int j = i;j<16;j++){
            for(int k = j;k<16;k++){
                if(i&j&k && cnt[i] && cnt[j] && cnt[k]){
                    if(i == j && j == k)
                        ans += (cnt[i]*(cnt[i]-1)*(cnt[i]-2))/6;
                    else if(i == j && j != k)
                        ans += (cnt[i]*(cnt[i]-1)/2)*cnt[k];
                    else if(i != j && j == k)
                        ans += cnt[i]*cnt[j]*(cnt[j]-1)/2;
                    else
                        ans += cnt[i]*cnt[j]*cnt[k];
                }
            }
        }
    }
    cout<<ans<<endl;
}
