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
vector<vector<double> > trian;
int main()
{
    for(int i = 1;i<=400;i++){
        trian.push_back(vector<double>());
        for(int j = 1;j<=i;j++){
            trian[i-1].push_back(0);
        }
    }
    in_T{
        int B, L, N;
        cin>>B>>L>>N;
        double total = B*750;
        vector<vector<double> > levels = trian, tmp;
        tmp = trian;
        levels[0][0] = total;
        for(int i = 1;i<L;i++){
            for(int j = 0;j<L;j++)
                for(int k = 0;k<=j;k++){
                    double flow = max(0.0, levels[j][k]-250);
                    cout<<flow<<endl;
                    tmp[i][j] += flow/3;
                    tmp[i+1][j] += flow/3;
                    tmp[i+1][j+1] += flow/3;
                }
            levels = tmp;
            tmp = trian;
        }
        for(int i = 0;i<L;i++){
            if(levels[i].size()<=N){
                cout<<levels[i][N-1]<<endl;
                break;
            }else
                N -= levels[i].size();

        }

}
}
