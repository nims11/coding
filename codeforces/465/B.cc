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
    int n;
    cin>>n;
    string str;
    cin>>str;
    int x = 0, y = 0;
    int ans = 0;
    int prev = -100;
    for(char c: str){
        if(c == 'U'){
            y++;
        }else
            x++;
        int dir;
        if(x > y)
            dir = 1;
        else
            dir = -1;
        if(x == y)
            dir = prev;
        if(prev == -100)
            prev = dir;
        else if(prev != dir){
            prev = dir;
            ans++;
        }
    }
    cout<<ans<<endl;
}
