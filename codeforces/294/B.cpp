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
int main()
{
    int n;
    in_I(n);
    vector<int> arr[3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<n-i;j++){
            int x;
            in_I(x);
            arr[i].push_back(x);
        }
        sort(arr[i].begin(), arr[i].end());
    }
    int xx = -1;
    for(int i = 0;i<arr[1].size();i++){
        if(arr[1][i] != arr[0][i]){
            xx = arr[0][i];
            break;
        }
    }
    if(xx == -1)
        xx = arr[0][arr[0].size()-1];
    cout<<xx<<endl;
    xx = -1;
    for(int i = 0;i<arr[2].size();i++)
        if(arr[2][i] != arr[1][i]){
            xx = arr[1][i];
            break;
        }
    if(xx == -1)
        xx = arr[1][arr[1].size()-1];

    cout<<xx<<endl;
}
