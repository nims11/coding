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
    int n = str.size();
    for(int i = 0;i<n;i++){
        int vi = str[i] - '0';
        if(vi%8 == 0){
                    cout<<"YES"<<endl;
            cout<<vi<<endl;
            return 0;
        }
        for(int j = i+1;j<n;j++){
            int vj = str[j] - '0';
            int x = vi*10 + vj;
            if(x%8 == 0){
                cout<<"YES"<<endl;
                cout<<x<<endl;
                return 0;
            }
            for(int k = j+1;k<n;k++){
                int vk = str[k] - '0';
                int x = vi*100+vj*10+vk;
                if(x%8 == 0){
                    cout<<"YES"<<endl;
                    cout<<x<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
