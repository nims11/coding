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
    in_T{
        int n;
        in_I(n);
        int arr[n];
        int sum = 0;
        int maxi = 0;
        for(int i = 0;i<n;i++){
            in_I(arr[i]);
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }
        if(sum != n || maxi == n)
            cout<<-1<<endl;
        else{
            vector<int>x;
            for(int i = 0;i<n;i++)for(int j = 0;j<arr[i];j++)
                x.push_back(i);
            assert(x.size() == n);
            int ans[n];
            for(int i = 0;i<n;i++)
                ans[i] = x[i];
            for(int i = 0;i<n;i++){
                if(ans[i] == i){
                    for(int j = 0;j<n;j++){
                        if(i != j && ans[j] != i){
                            swap(ans[i], ans[j]);
                            break;
                        }
                    }
                }
            }
            bool flag = true;
            for(int i = 0;i<n;i++)
                if(i == ans[i]){
                    cout<<-1<<endl;
                    flag = false;
                    break;
                }
            if(flag)
                for(int i = 0;i<n;i++)
                    cout<<ans[i]+1<<" ";
            cout<<endl;
        }
    }
}
