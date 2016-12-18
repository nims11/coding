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
char str[50][50];
int r, c;
int main(){
    in_I(r);
    in_I(c);
    for(int i = 0;i<r;i++)
        in_S(str[i]);
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                bool flag2 = true;
                if(i>=2 && j >=2 && str[i][j] != 'W' && str[i][j] != '?'){
                    for(int k = i;k>i-3 && flag2;k--)
                        for(int l = j;l>j-3 && flag2;l--){
                            if(str[k][l] != str[i][j] && str[k][l] != '?')
                                flag2 = false;
                        }
                    if(flag2){
                        flag = true;
                        for(int k = i;k>i-3;k--)
                            for(int l = j;l>j-3;l--){
                                str[k][l] = '?';
                            }
                    }

                }
                if(str[i][j] == '?'){
                    char ch = 0;
                    flag2 = true;
                    for(int k = i;k>i-3 && flag2;k--)
                        for(int l = j;l>j-3 && flag2;l--)
                        {
                            if(str[k][l] == 'W'){
                                flag2 = false;
                                break;
                            }
                            if(str[k][l] != '?'){
                                if(ch == 0)
                                    ch = str[k][l];
                                else if(ch != str[k][l]){
                                    flag2 = false;
                                    break;
                                }
                            }
                        }
                    if(flag2 && ch != 0){
                        flag = true;
                        for(int k = i;k>i-3;k--)
                            for(int l = j;l>j-3;l--){
                                str[k][l] = '?';
                            }
                    }
                }
            }
        }
    }
    for(int i = 0;i<r;i++)
        for(int j = 0;j<c;j++)
            if(str[i][j] != '?' && str[i][j] != 'W'){
                cout<<"NO"<<endl;
                return 0;
            }
    cout<<"YES"<<endl;
}
