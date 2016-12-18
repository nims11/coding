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
    int n;
    in_I(n);
    int arr[n];
    for(int i = 0;i<n;i++)
        in_I(arr[i]);
    sort(arr, arr+n);
    vector<int> piles;
    for(int i = 0;i<n;i++){
        int mini = -1, minval = 10000;
        for(int j = 0;j<piles.size();j++){
            if(piles[j] < minval)
                mini = j, minval = piles[j];
        }
        if(mini == -1 || minval > arr[i]){
            piles.push_back(1);
        }else{
            piles[mini]++;
        }
    }
    cout<<piles.size()<<endl;
}
