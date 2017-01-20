#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ans;
    int i = 0;
    for(i = 0;i<n-3;i+=2){
        ans.push_back(2);
    }
    if(i + 2 == n)
        ans.push_back(2);
    else

        ans.push_back(3);
    printf("%d\n", ans.size());
    for(int x: ans){
        printf("%d ",x);
    }
    printf("\n");
}
