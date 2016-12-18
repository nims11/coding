/*
    Nimesh Ghelani (nims11)
    Take the shortest time each of them takes to reach the boundary. Then find if there is a boundary cell that can be reached safely (mouse have the least time for that cell).
    Proof: by induction.
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
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
int mod(int a)
{
    return a>0?a:-a;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int grid[n][m];
    int k;
    in_I(k);
    while(k--)
    {
        int coord[6];
        for(int i=0;i<6;i++)
        {
            in_I(coord[i]);
            coord[i]--;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                grid[i][j] = min(mod(coord[2]-i)+mod(coord[3]-j), mod(coord[4]-i)+mod(coord[5]-j));
        }
        bool flag = false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if((i!=0 && i!=n-1) && (j!=0 && j!=m-1))continue;
//                cout<<"s"<<endl;
//                cout<<i<<" "<<j<<endl;
                if(mod(coord[0]-i)+mod(coord[1]-j)<grid[i][j])
                {
                    flag=true;
                    i=n;
                    break;
                }
            }
        cout<<(flag?"YES":"NO")<<endl;
    }
}
