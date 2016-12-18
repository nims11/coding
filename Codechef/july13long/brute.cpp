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
    in_T
    {
        int n;
        in_I(n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            in_I(arr[i]);
            cout<<arr[i]<<" ";
        }
        newline;
        int ans = 0;
        for(int i1 = 0;i1<n-1; i1++)
            for(int j1 = i1+1; j1<n;j1++)
            {
//                cout<<i1<<" "<<j1<<" ";
                bool flag = true;
                for(int i2 = i1+1; i2<n-1; i2++)
                {
                    int j2 = j1-i1+i2;
                    if(j2>=n)continue;
                    bool x = false;
                    for(int k=1;k<=j1-i1;k++)
                    {
                        if(arr[i1+k] - arr[i1+k-1] != arr[i2+k] - arr[i2+k-1])
                        {
                            x = true;
                            break;
                        }
                    }
                    if(!x)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    ans++;
            }
        cout<<ans<<endl;
    }
}
