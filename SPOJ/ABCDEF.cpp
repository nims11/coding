//GQ
/*
 * Objective: total number of sextuples (a,b,c,d,e,f) from a given set of numbers, d!=0 that satisfy (a*b+c)/d - e=f
 *
 * First of all, modify the equation as
 * a*b + c = d * (e+f)
 * store all possible LHS and RHS values in O(n^3) time in two separate lists.
 * Sort the second list.
 * from the first list find the number of occurances in second list which is the answer.
 *
 * NOTE: take case of d!=0.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int main()
{
    int n,arr[100];
    in_I(n);
    vector<int>foo1,foo2;
    for(int i=0;i<n;i++)
    in_I(arr[i]);

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    for(int k=0;k<n;k++)
    {
//        cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
        foo1.push_back(arr[i]*arr[j]+arr[k]);
        if(arr[i])
        foo2.push_back(arr[i]*(arr[j]+arr[k]));
    }
    int ans=0;
    sort(foo2.begin(),foo2.end());
    int a;
    for(int i=0;i<foo1.size();i++)
    {
        a=upper_bound(foo2.begin(),foo2.end(),foo1[i])-lower_bound(foo2.begin(),foo2.end(),foo1[i]);
        ans+=a;
    }
    cout<<ans<<endl;
}
