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
    if(n == 1){
        printf("-1\n");
        return 0;
    }
    int cd = arr[1]-arr[0];
    bool isAP = true;
    for(int i = 1;i<n;i++)
        if(arr[i]-arr[i-1] != cd){
            isAP = false;
            break;
        }
    vector<int> ans;
    if(isAP){
        ans.push_back(arr[0]-cd);
        ans.push_back(arr[n-1]+cd);
        if(n == 2){
            if(cd%2 == 0){
                ans.push_back(arr[0]+cd/2);
            }
        }
    }else{
        int cd1 = arr[1]-arr[0];
        int cd2 = arr[2]-arr[1];
        if(cd1 == cd2){
            for(int i = 1;i<n;i++)
                if(arr[i]-arr[i-1] != cd1){
                    if(ans.size() != 0){
                        printf("0\n");
                        return 0;
                    }
                    if(arr[i]-cd1 == arr[i-1]+cd1)
                        ans.push_back(arr[i]-cd1);
                }
        }else{
            if(n>3){
                int cd3 = arr[3]-arr[2];
                for(int i = 1;i<n;i++)
                if(arr[i]-arr[i-1] != cd3){
                    if(ans.size() != 0){
                        printf("0\n");
                        return 0;
                    }
                    if(arr[i]-cd3 == arr[i-1]+cd3)
                        ans.push_back(arr[i]-cd3);
                }
            }else{
                if(arr[0]+cd2 == arr[1]-cd2){
                    ans.push_back(arr[0]+cd2);
                }else if(arr[1]+cd1 == arr[2]-cd1)
                    ans.push_back(arr[2]-cd2);
            }
        }
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for(int i = 0;i<ans.size(); i++)
        if(i == 0 || ans[i] != ans[i-1] )
        printf("%d ", ans[i]);
    if(ans.size() > 0)
    printf("\n");
}
