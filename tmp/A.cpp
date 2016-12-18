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
string ans;
int R,P,S,N;
int R_1,P_1,S_1,N_1;
string getans(char c, int curN){
    if(curN == 0){
        switch(c){
            case 'P':
                return "P";
                break;
            case 'R':
                return "R";
                break;
            case 'S':
                return "S";
                break;
        }
    }
    string l, r;
    switch(c){
        case 'P':
            l = getans('P', curN-1), r = getans('R', curN-1);
            break;
        case 'R':
            l = getans('R', curN-1), r = getans('S', curN-1);
            break;
        case 'S':
            l = getans('P', curN-1), r = getans('S', curN-1);
            break;
    }
    if(l < r)
        return l + r;
    return r+l;
}
string getans(char c){
    return getans(c, N);
}
bool foo(string ans){
    int rr=0, pp=0, ss=0;
    for(char c: ans){
        if(c == 'R')
            rr++;
        else if(c == 'S')
            ss++;
        else if(c == 'P')
            pp++;
    }
    return rr == R && pp == P && ss == S;
}
int main(){
   int z = 0; 
   int t;
   cin>>t;
   for(int z = 1;z<=t;z++){
       cin>>N_1>>R_1>>P_1>>S_1;
       cout<<"Case #"<<z<<": ";
       N = N_1, R = R_1, P = P_1, S = S_1;
       string ans = getans('P');
       if(!foo(ans))
           ans = getans('R');
       else{
        string ans2 = getans('R');
        if(foo(ans2) && ans2 < ans)
            ans = ans2;
       }
       if(!foo(ans))
           ans = getans('S');
       else{
        string ans2 = getans('S');
        if(foo(ans2) && ans2 < ans)
            ans = ans2;
       }
       if(foo(ans)){
        cout<<ans<<endl;
       }else
           cout<<"IMPOSSIBLE"<<endl;
   }
}
