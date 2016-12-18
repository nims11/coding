/*
    Nimesh Ghelani (nims11)
    simulation using stack
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
int n;char str[20002];
int main()
{
    for(int T=0;T<10;T++)
    {
        in_I(n);
        in_S(str);
        stack<int> simu;
        simu.push(20500);
        int mini = 21000;
        int ans = 0, tmp;
        int curr=0;
        for(int i=0;i<n && !simu.empty();i++)
        {
//            cout<<str[i]<<endl;
            tmp = simu.top();
            simu.pop();
            if(str[i]=='1')
            {
                curr++;
                simu.push(tmp-1);
                simu.push(tmp-1);
                if(tmp<mini)
                {
                    mini = tmp;
                    ans = curr;
                }
            }
        }
        printf("%d\n", ans);
    }
}
