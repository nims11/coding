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
int arr[10000];
int n,f;
bool getans(double ans)
{
    int anss = 0;
    for(int i=0;i<n && anss<f;i++)
    {
        anss += arr[i]/ans;
    }
    return anss>=f;
}
double pi = acos(-1);
int main()
{
    in_T
    {
        scanf("%d%d", &n, &f);
        f++;
        int mini = 1000000000, maxi = -1;
        for(int i=0;i<n;i++)
        {
            in_I(arr[i]);
            arr[i]*=arr[i];
            mini = min(arr[i], mini);
            maxi = max(arr[i], maxi);
        }
        double start = double(mini)/f, end = maxi;
        while(end-start>0.000001)
        {
            double mid = (end+start)/2;
            if(getans(mid))
            {
                start = mid;
            }else
                end = mid;
        }
        printf("%.4lf\n", end*pi);
    }
}
