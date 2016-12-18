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
int main()
{
    int n, c, x;
    cin>>n;
    vector<int> piles[n];
    vector<int> mid;
    for(int i = 0;i<n;i++){
        in_I(c);
        while(c--){
            in_I(x);
            piles[i].push_back(x);
        }
        if(piles[i].size()%2 == 1){
            mid.push_back(piles[i][piles[i].size()/2]);
        }
    }
    sort(mid.begin(), mid.end());
    int l = 0, r = 0;
    int cnt = 0;
    for(int i = (int)mid.size()-1;i>=0;i--){
        if(cnt%2 == 0){
            l += mid[i];
        }else
            r += mid[i];
        cnt++;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0 ;j<piles[i].size()/2;j++){
            l += piles[i][j];
        }
        for(int j = (piles[i].size()+1)/2; j<piles[i].size();j++)
            r+=piles[i][j];
    }
    cout<<l<<" "<<r<<endl;
}
