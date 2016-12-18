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
    cin>>n;
    vector<int> x;
    for(int i = 0;i<n;i++){
        int y;
        cin>>y;
        x.push_back(y-n+i);
    }
    sort(BE(x));
    bool flag = true;
    vector<int> res;
    for(int i = 0;i<n;i++){
        res.push_back(x[i]+n-i);
        if(res[i] < 0 || (i!=0 && res[i]<res[i-1])){
            cout<<":("<<endl;
            return 0;
        }
    }
    for(int i = 0;i<n;i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
