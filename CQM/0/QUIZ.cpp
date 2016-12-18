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
    int s1, s2, s3, w1, w2;
    in_T
    {
        cin>>s1>>s2>>s3>>w1>>w2;
        int arr[4];
        arr[0] = max(s1+w1, s2+w2);
        arr[1] = max(s1+w1, s2-w2);
        arr[2] = max(s1-w1, s2+w2);
        arr[3] = max(0, max(s1-w1, s2-w2));
        int maxx = 0, maxi;
        for(int i = 0; i<4; i++)
        {
            int x = count(arr, arr+4, arr[i]);
            if(x>maxx)
                maxx = x, maxi = i;
            else if(x == maxx && arr[maxi]>arr[i])
                maxx = x, maxi = i;
        }
        printf("%d\n", arr[maxi]);
    }
}
