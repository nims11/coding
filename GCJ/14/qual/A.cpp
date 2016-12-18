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
    int z = 0;
    in_T{
        z++;
        int N;set<int> X;
        in_I(N);
        for(int i = 0;i<4;i++)
            for(int j = 0;j<4;j++)
            {
                int y;
                in_I(y);
                if(i == N-1)
                    X.insert(y);
            }
        int match = 0, ans;
        in_I(N);
        for(int i = 0;i<4;i++)
            for(int j = 0;j<4;j++)
            {
                int y;
                in_I(y);
                if(i == N-1){
                    if(X.find(y) != X.end())
                        match++, ans = y;
                }
            }
        cout<<"Case #"<<z<<": ";
        if(match == 0){
            cout<<"Volunteer cheated!\n";
        }else if(match == 1){
            cout<<ans<<endl;
        }else
            cout<<"Bad magician!\n";
    }
}
