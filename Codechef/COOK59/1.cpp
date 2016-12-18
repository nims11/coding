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
        int n, k;
        in_I(n);
        in_I(k);
        int arr[n];
        long long S = 0;
        for(int i = 0;i<n;i++){
            int x;
            in_I(x);
            S += x;
        }
        if(S%2 == 0){
            if(k == 1)
                cout<<"odd"<<endl;
            else
                cout<<"even"<<endl;
        }else{
            cout<<"even"<<endl;
        }
    }
}
