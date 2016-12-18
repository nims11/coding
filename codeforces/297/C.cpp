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
    string str;
    cin>>str;
    int m;
    cin>>m;
    vector<int> arr;
    int x;
    for(int i = 0;i<m;i++){
        cin>>x;
        x--;
        arr.push_back(x);
    }
    sort(BE(arr));
    int n = str.size();
    string res;
    for(int i = 0;i<n;i++)
        res.push_back(' ');
    for(int i = 0;i<n;i++){
        x = i;
        if(n-i-1 < i)
            x = n-i-1;
        int ss = int(upper_bound(BE(arr), x) - arr.begin());
        if(ss %2 == 0)
            res[i] = str[i];
        else
            res[n-i-1] = str[i];
    }
    cout<<res<<endl;
}
