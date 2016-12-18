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
    in_T{
        int x1,x2,y1,y2, x3,x4,y3,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        int ar1 = (y2-y1)*(x2-x1), ar2 = (y4-y3)*(x4-x3);
        if(max(x1, x3) > min(x2, x4) || max(y1, y3) > min(y2, y4)){
            cout<<ar1+ar2<<endl;
        }else{
            int y11, y22, x11, x22;
            x11 = max(x1, x3);
            y11 = max(y1, y3);
            x22 = min(x2, x4);
            y22 = min(y2, y4);
            cout<<ar1+ar2-(y22-y11)*(x22-x11)<<endl;
        }
    }
}
