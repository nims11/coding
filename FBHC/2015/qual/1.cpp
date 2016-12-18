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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int main()
{
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        string str;
        cin>>str;
        int maxi = atoi(str.c_str()), mini = atoi(str.c_str());
        for(int i = 0;i<str.length();i++){
            for(int j = i+1;j<str.length();j++){
                string str2 = str;
                swap(str2[i], str2[j]);
                if(str2[0] == '0')
                    continue;
                int cur = atoi(str2.c_str());
                maxi = max(cur, maxi);
                mini = min(cur, mini);
            }
        }
        cout<<mini<<" "<<maxi<<endl;
    }
}
