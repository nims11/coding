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

bool isvo(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
int main(){
    int n;
    string str;
    cin>>n>>str;
    cout<<str[0];
    char prev = str[0];
    for(int i = 1; i < str.size(); i++){
        if(isvo(str[i])){
            if(isvo(prev)){}
            else{
                prev = str[i];
                cout<<str[i];
            }
        }else{
            cout<<str[i];
            prev = 0;}

    }
    cout<<endl;
}
