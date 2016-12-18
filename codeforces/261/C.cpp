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
    int n, k, d;
    in_I(n); in_I(k); in_I(d);
    if(k>=n){
        for(int i = 0;i<d;i++)
            for(int j = 1;j<=k;j++)
                printf("%d ", j);
        newline;
        return 0;
    }
    if(n/k+(n%k!=0) - 1 > (d-1)*(n-1))cout<<-1<<endl;
    else{
        int arr[n];
        int tmp = 0;
        vector<int> mems[k];
        int ptrs[k];
        for(int i = 0;i<n;i++){
            arr[i] = tmp;
            mems[tmp++].push_back(i);
            tmp %= k;
        }
        for(int i =0;i<k;i++)ptrs[i] = 1;
        for(int i = 0;i<d;i++){
            for(int j = 0;j<n;j++)
                printf("%d ", arr[j]+1);
            newline;
            for(int j = 0;j<k;j++){
                int tmp = 0;
                while(tmp < k && ptrs[j] < mems[j].size()){
                    if(tmp == j){
                        tmp++;
                        continue;
                    }
                    arr[mems[j][ptrs[j]]] = tmp++;
                    ptrs[j]++;
                }
            }
        }
    }
}
