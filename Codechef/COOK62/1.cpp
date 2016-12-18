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
    in_T{
        int N, K;
        in_I(N);
        in_I(K);
        vector<string> dict;
        map<string, int> foo;
        for(int i = 0;i<N;i++){
            string str;
            cin>>str;
            dict.push_back(str);
            foo[str] = 0;
        }
        for(int i = 0;i<K;i++){
            int x;
            in_I(x);
            while(x--){
                string str;
                cin>>str;
                if(foo.find(str) != foo.end())
                    foo[str] = 1;
            }
        }
        for(string str: dict){
            printf(foo[str]?"YES ":"NO ");
        }
        newline;
    }
}
