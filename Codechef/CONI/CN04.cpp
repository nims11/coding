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
    in_T{
        string str;
        cin>>str;
        set<string> s;
        for(int i = 0;i<str.size();i++){
            for(int j = i;j<str.size();j++)
                s.insert(str.substr(i, j-i+1));
        }
        cout<<s.size()<<endl;
    }
}
