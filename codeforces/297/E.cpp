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
long long fact[20];
int main()
{
    fact[0] = 1;
    for(int i = 1;i<20;i++)
        fact[i] = fact[i-1]*i;
    int n, k; long long s;
    in_I(n);
    in_I(k);in_L(s);
    int arr[n];
    for(int i = 0;i<n;i++)in_I(arr[i]);
    map<long long, vector<int> > poss;
    long long res = 0;
    for(int i = 0;i<(1<<n);i++){
        long long sum = 0;
        int tot = __builtin_popcountll(i);
        if(tot > k)continue;
        for(int j = 0;j<n;j++){
            if((i&(1<<j))){
                if(arr[j] < 20){
                    sum += fact[arr[j]];
                }else{
                    break;
                }
            }
            if(j == n-1){
                poss[sum].push_back(i);
            }

        }
    }
    cout<<"AS"<<endl;
    for(int i = 0;i<(1<<n);i++){
        long long sum = 0;
        for(int j = 0;j<n;j++){
            if((i&(1<<j))){
                sum += arr[j];
            }
        }
        long long rem = s - sum;
        if(rem == 0){
            res++;
        }else if(poss.find(rem) != poss.end()){
            vector<int> &x = poss[rem];
            for(int z = 0;z<x.size();z++){
                if(x[z] & i);
                else
                    res++;
            }
        }
    }
    cout<<res<<endl;
}
