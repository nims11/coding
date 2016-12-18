/*
    Nimesh Ghelani (nims11)
*/
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
int set_parent[300010];
int sizes[300010];
int setid[300010];
void set_union(int s1, int s2){
    if(s2 < s1)
        set_union(s2, s1);
    else{
        set_parent[s2] = s1;
    }
}
int set_find(int x){
    if(set_parent[x] == x)
        return x;
    return (set_parent[x]=set_find(set_parent[x]));
}
int main()
{
    int n, m;
    in_I(n);
    in_I(m);
    char str[n+1];
    in_S(str);
    set<pair<int, int> > stash;
    int curSz = 0;
    int res = 0;
    for(int i = 0;i<n;i++){
        if(str[i] == '.'){
            set_parent[i] = i-curSz;
            curSz++;
        }
        if(str[i] != '.' || i == n-1){
            if(str[i] != '.')
                set_parent[i] = i;
            if(curSz){
                // stash.insert(make_pair(i-(str[i]!='.'), curSz));
                res += curSz-1;
                curSz = 0;
            }
        }
    }
    while(m--){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        x--;
        if(str[x] == c){
            printf("%d\n", res);
            continue;
        }
        if(c == '.'){
            str[x] = c;
            if(x > 0 && str[x-1] == '.'){
                res++;
                set_union(x, x-1);
            }
            if(x < n-1 && str[x+1] == '.'){
                res++;
                set_union(x, x+1);
            }
        }else{

        }
        // cout<<stash.begin()->first<<" "<<stash.begin()->second<<endl;
        printf("%d\n", res);
    }
}
