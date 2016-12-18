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
int n;
int arr[1000000];
int leftx[1000000], rightx[1000000];
int main()
{
    in_I(n);
    for(int i = 1;i<=n;i++)
        in_I(arr[i]);
    stack<pair<int, int> > maxi;
    maxi.push(make_pair(-1, 0));
    for(int i = 1;i<=n;i++){
        pair<int, int> t;
        while((t = maxi.top()).first >= arr[i]){
            maxi.pop();
        }
        leftx[i] = i - t.second;
        maxi.push(make_pair(arr[i], i));
    }
    while(!maxi.empty())
        maxi.pop();
    maxi.push(make_pair(-1, n+1));
    for(int i = n;i>=1;i--){
        pair<int, int> t;
        while((t = maxi.top()).first >= arr[i]){
            maxi.pop();
        }
        rightx[i] = t.second - i;
        maxi.push(make_pair(arr[i], i));
    }
    vector<pair<int, int> > res;
    for(int i = 1;i<=n;i++){
        res.push_back(make_pair(rightx[i]+leftx[i]-1, -arr[i]));
    }
    res.push_back(make_pair(0, -1));
    sort(BE(res));
    int res2[n+1];
    int curMax = -1;
    for(int i = res.size()-1;i>=1;i--){
        curMax = max(-res[i].second, curMax);
        for(int j = res[i-1].first+1;j<=res[i].first;j++)
            res2[j] = curMax;
    }
    for(int i = 1;i<=n;i++)
        printf("%d ", res2[i]);
    printf("\n");
}
