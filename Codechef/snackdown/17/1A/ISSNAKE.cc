#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

char str[550][550];
bool vis[550][550];
int n;
int main(){
    in_T{
        in_I(n);
        for(int i = 0;i<2;i++){
            in_S(str[i]);
            for(int j = 0;j<n;j++)
                vis[i][j] = false;
        }
        bool started = false;
        bool possible = true;
        for(int j = 0;j<n;j++){
            char ch[2] = {str[0][j], str[1][j]};
            if(!started ){
                if(ch[0] == '#' || ch[1] == '#'){
                    started = true;
                    if(ch[0] == '#'){
                        vis[0][j] = true;
                    }
                    if(ch[1] == '#'){
                        vis[1][j] = true;
                    }
                }
            }else {
                if(ch[0] == '#' && ch[1] == '#'){
                    if(vis[0][j-1])
                        vis[1][j] = true;
                    if(vis[1][j-1])
                        vis[0][j] = true;
                }else if(ch[0] == '#'){
                    if(vis[0][j-1])
                        vis[0][j] = true;
                }else if(ch[1] == '#'){
                    if(vis[1][j-1])
                        vis[1][j] = true;
                }else{
                    vis[0][j] = vis[1][j] = false;
                }
            }

            if((ch[0] == '#' || ch[1] == '#') && !(vis[1][j] || vis[0][j])){
                possible = false;
                break;
            }
        }
        printf(possible?"yes\n":"no\n");
    }
}
