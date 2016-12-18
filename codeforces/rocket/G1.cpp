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
int n, k;
vector<int> arr;
int inv(vector<int> &arr){
    int ret = 0;
    for(int i = 0;i<arr.size();i++)
        for(int j = i+1;j<arr.size();j++)
            if(arr[i] > arr[j])
                ret++;
    return ret;
}
long double tot;
long double res = 0;
void getans(vector<int> &arr, int k){
    if(k == 0){
        long double ret = inv(arr)/tot;
        res += ret;
        return;
    }
    long double ret = 0;
    for(int i = 0;i<n;i++)
        for(int j = i;j<n;j++){
            reverse(arr.begin()+i, arr.begin()+j+1);
            getans(arr, k-1);;
            reverse(arr.begin()+i, arr.begin()+j+1);
        }
}
int main()
{
    cin>>n>>k;
    tot = 1;
    for(int i = 0;i<k;i++)
        tot *= n*(n+1)/2;
    int x;
    for(int i = 0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    cout<<fixed;
    getans(arr, k);
    cout<<setprecision(10)<<res<<endl;;
}
