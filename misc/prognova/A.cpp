#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

int main(){
    string str;
    cin>>str;
    int a = 0, b = 0, c= 0;
    for(char ch: str){
        if(ch == 'T')a++;
        if(ch == 'G')b++;
        if(ch == 'C')c++;
    }
    cout<<(a*a+b*b+c*c+7*min(a, min(b, c)))<<endl;
}
