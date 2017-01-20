#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int main(){
    int n;
    string str;
    cin>>n>>str;
    int req = n / 4;
    if(n % 4 != 0){
        printf("===\n");
        return 0;
    }
    int cnt[255] = {0};
    for(char s: str){
        cnt[s]++;
    }
    if(cnt['A'] > req || cnt['G']  > req || cnt['T'] > req  || cnt['C'] > req){
        printf("===\n");
        return 0;
    }
    for(int i = 0;i<str.length();i++){
        if(str[i] == '?'){
            char c;
            if(cnt['A'] < req){
                cnt['A']++;
                c = 'A';
            }else if(cnt['G'] < req){
                cnt['G']++;
                c = 'G';
            }else if(cnt['T'] < req){
                cnt['T']++;
                c = 'T';
            }else {
                cnt['C']++;
                c = 'C';
            }
            str[i] = c;
        }
    }
    cout<<str<<endl;
}
