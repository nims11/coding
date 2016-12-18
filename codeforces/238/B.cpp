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
int arr[1000001];
int x;
vector<int> ans;
int main()
{
    int n;
    in_I(n);
    for(int i = 0;i<n;i++){
        in_I(x);
        arr[x] = 1;
    }
    int m = 0;
    int flag = 0;
    for(int i = 2;i<1000001;i++){
        if(arr[i] == 1){
            if(arr[1000000-i+1] == 0){
                arr[1000000-i+1] = 2;
                ans.push_back(1000000-i+1);
            }else{
                arr[1000000-i+1] = 2;
                flag++;
            }
        }
    }
    for(int i = 1;flag && i<=1000000;i++){
        if(arr[i] == 0 && arr[1000001-i] == 0)
        {
            flag--;
            arr[i] = arr[1000001-i] = 2;
            ans.push_back(i);
            ans.push_back(1000001-i);

        }
    }
    if(ans.size() == 0){
        ans.push_back(1000000);
    }
    printf("%d\n", ans.size());
    for(int i = 0;i<ans.size();i++){
        printf("%d ", ans[i]);
    }
    newline;
}
