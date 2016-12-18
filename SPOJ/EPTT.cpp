/*
    Nimesh Ghelani (nims11)
    rem[i][j]
    stores the number of available profs at time i, who have spent 30*(j+1) amount of stretch.
    sort the start times and choose greedily the prof with least spent time
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
int main()
{
    int r;
    in_I(r);
    int arr[r];
    for(int i=0;i<r;i++)
        in_I(arr[i]);
    sort(arr, arr+r);
    int ans = 0;
    int rem[1450][3] = {{0}};
    for(int i=0;i<r;i++)
    {
        if(rem[arr[i]][0])
        {
            rem[arr[i]][0]--;
            rem[arr[i]+30][1]++;
        }else if(rem[arr[i]][1])
        {
            rem[arr[i]][1]--;
            rem[arr[i]+30][2]++;
        }else if(rem[arr[i]][2])
        {
            rem[arr[i]][2]--;
        }else
        {
            ans++;
            rem[arr[i]+30][0]++;
        }
    }
    cout<<ans<<endl;
}
