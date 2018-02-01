#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;

int main(){
    in_T{
        int n;
        in_I(n);
        char str[n+10];
        in_S(str);
        int foo[26] = {0};
        for(int i = 0; i < n;i++){
            int c = str[i] - 'a';
            cout<<c<<" "<<foo[c]<<endl;
            str[i] = ((c + foo[c]) % 26) + 'a';
            /* foo[c]++; */
        }
        cout<<str<<endl;
    }
}
