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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int z = 0;
int main()
{
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int N, G[3];
        for(int i = 0;i<3;i++)
            cin>>G[i];
        cin>>N;
        int foo[N][3];
        for(int i = 0;i<N;i++)
            for(int j = 0;j<3;j++)
                cin>>foo[i][j];
        bool flag = false;
        for(int i = 0;i<(1<<N);i++){
            int GG[3];
            for(int j = 0;j<3;j++)
                GG[j] = G[j];
            for(int j = 0;j<N;j++){
                if(i & (1<<j)){
                    for(int k = 0;k<3;k++)
                        GG[k] -= foo[j][k];
                }
            }
            if(GG[0] == 0 && GG[1] == 0 && GG[2] == 0){
                flag = true;
                break;
            }
        }
        cout<<(flag?"yes":"no")<<endl;
    }
}
