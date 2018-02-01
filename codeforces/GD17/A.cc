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
bool isvowel(char c){
    return (c == 'a' || c == 'e'| c == 'i' || c == 'o' || c == 'u');
}
int main(){
    string str;
    cin>>str;
    int ans = 0;
    for(char c: str){
        if(isvowel(c)){
            ans++;
        }
        if(isdigit(c)){
            int x = c - '0';
            ans += (x % 2);
        }
    }
    cout<<ans<<endl;
}
