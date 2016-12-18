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


using namespace std;
int main()
{
    int n;
    in_I(n);
    int arr[n];
    for(int i = 0;i<n;i++)
        in_I(arr[i]);
    string m;
    cin>>m;
    int ans = 0;
    int y = 0;
    for(int i = 0; i < n;i++)
    {
        ans += (m[i]-'0')*arr[i];
        y += arr[i];
    }
    int x = 0;
    for(int i = n-1;i>=0;i--)
    {
        y -= arr[i];
        if(m[i] == '1')
        {
//            cout<<x<<" "<<y<<endl;
            ans = max(ans, x+y);
        }
        x += (m[i]-'0')*arr[i];
    }
    cout<<ans<<endl;
}
