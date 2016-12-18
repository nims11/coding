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
    vector<int> arr[5];
    arr[0].push_back(1);arr[0].push_back(1);arr[0].push_back(2);
    arr[1].push_back(1);arr[1].push_back(1);arr[1].push_back(2);
    arr[2].push_back(2);arr[2].push_back(2);arr[2].push_back(2);
    arr[3].push_back(2);arr[3].push_back(2);arr[3].push_back(3);arr[3].push_back(3);
    arr[4].push_back(2);arr[4].push_back(2);arr[4].push_back(3);arr[4].push_back(3);
    in_T{
        int n;
        in_I(n);
        long long sum = 0;
        for(int i = 0;i<5;i++){
            long long cur = max(0, n-arr[i][0]+1);
            for(int j = 1;j<arr[i].size();j++){
                cur *= max(0, n-arr[i][j]);
            }
            cout<<cur<<endl;
            sum += cur;
        }
        printf("%lld\n", sum);
    }
}
