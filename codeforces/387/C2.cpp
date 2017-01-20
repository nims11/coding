#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
bool field[2000000];
int main(){
    int n;
    string str;
    cin>>n>>str;
    int d_cnt = 0, r_cnt = 0;
    for(char c: str){
        if(c == 'D')
            d_cnt++;
        else
            r_cnt++;
    }
    set<int> foo1, foo2;
    for(int i = 0;i<n;i++){
        if(str[i] == 'D'){
            foo1.insert(i);
        }else
            foo2.insert(i);
    }
    while(d_cnt > 0 && r_cnt > 0){
        for(int i = 0;i<n && d_cnt > 0 && r_cnt > 0;i++){
            if(!field[i]){
                int nxt_idx;
                if(str[i] == 'D'){
                    auto it = foo2.lower_bound(i);
                    if(it == foo2.end()){
                        it = foo2.begin();
                    }
                    nxt_idx = *it;
                    foo2.erase(it);
                    r_cnt--;
                    field[nxt_idx] = 1;
                }
                if(str[i] == 'R'){
                    auto it = foo1.lower_bound(i);
                    if(it == foo1.end()){
                        it = foo1.begin();
                    }
                    nxt_idx = *it;
                    foo1.erase(it);
                    d_cnt--;
                    field[nxt_idx] = 1;
                }
            }
        }
    }
    printf(d_cnt?"D\n":"R\n");
}
