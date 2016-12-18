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
    int o=0, e=0,n,k;
    cin>>n>>k;
    int x;
    for(int i = 0;i<n;i++){
        cin>>x;
        if(x%2 == 0)
            e++;
        else
            o++;
    }
    int ch = n-k;
    int d_ch = ch/2;
    if(d_ch >= o){
        cout<<"Daenerys"<<endl;
    }else{
        int cur_st = o%2;
        e = min(e, d_ch);
        if(e%2 == 1)
            cur_st = !cur_st;
    }
}
