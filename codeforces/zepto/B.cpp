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
#define BE(a) a.begin(), a.end()

using namespace std;
int arr[2000];

    int n;
int res = 0;
int getans(int idx){
    if(idx >= (1<<(n)))return 0;
    int lid = 2*idx, rid = 2*idx+1;
    int ledge = arr[lid], redge = arr[rid];
    int lans = getans(2*idx)+ledge;
    int rans = getans(2*idx+1)+redge;
    res += abs(lans-rans);
    // cout<<idx<<" "<<res<<endl;
    return max(lans, rans);
}
int main()
{
    cin>>n;
    for(int i = 0;i<(1<<(n+1))-2;i++)
        cin>>arr[i+2];
    getans(1);
    cout<<res<<endl;
}
