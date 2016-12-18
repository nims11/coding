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
    int n;
    in_I(n);
    char str[10];
    int cnt[5][101] = {0};
    int tot[5] = {0};
    for(int i = 0;i<n;i++){

        int x;
        scanf("%s %d", str, &x);
        cnt[str[0]-'A'][x]++;
        tot[str[0]-'A']++;
    }
    for(int i = 0;i<5;i++){
        vector<int> res;
        for(int j = 0;j<=100;j++){
            if(10*cnt[i][j] > tot[i])
                res.push_back(j);
        }
        if(res.size() == 0)
            cout<<"Nothing Unusual";
        else
            for(int j = 0;j<res.size();j++)
                cout<<res[j]<<" ";
        cout<<endl;
    }
}
