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
            curSz++;
        }
        if(str[i] != '.' || i == n-1){
            if(curSz){
                stash.insert(make_pair(i-(str[i]!='.'), curSz));
                res += curSz-1;
                curSz = 0;
            }
        }
    }
        // for(set<pair<int, int> >::iterator it = stash.begin(); it != stash.end(); it++)
        //     cout<<it->first<<" "<<it->second<<endl;
    while(m--){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        x--;
        if(str[x] == c){
            printf("%d\n", res);
            continue;
        }
        str[x] = c;
        if(c != '.'){
            set<pair<int, int> >::iterator it = stash.lower_bound(make_pair(x, 0));
            if(it != stash.end()){
                int st = it->first - it->second + 1;
                int end = it->first;
                // cout<<st<<" "<<end<<endl;
                if(x >= st && x <= end){
                    stash.erase(it);
                    res -= end-st;
                    if(x > st){
                        res += x-st-1;
                        stash.insert(make_pair(x-1, x-st));
                    }
                    if(x < end){
                        res += end-x-1;
                        stash.insert(make_pair(end, end-x));
                    }
                }
            }
        }else{
            set<pair<int, int> >::iterator it = stash.lower_bound(make_pair(x, 0)), it2;
            if(it != stash.end()){
                int st = it->first - it->second + 1;
                int end = it->first;
                if(x == st-1){
                    stash.erase(it);
                    stash.insert(make_pair(end, end-st+2));
                    res++;
                }else
                    stash.insert(make_pair(x, 1));
            }else{
                stash.insert(make_pair(x, 1));
            }
            it = stash.lower_bound(make_pair(x-1, 0));
            if(it->first == x-1){
                it2 = ++it;
                --it;
                int end = it2->first;
                int sz = it2->second + it->second;
                res++;
                stash.erase(it);
                stash.erase(stash.lower_bound(make_pair(x, 0)));
                stash.insert(make_pair(end, sz));
            }
        }
        // cout<<stash.begin()->first<<" "<<stash.begin()->second<<endl;
        printf("%d\n", res);
        // for(set<pair<int, int> >::iterator it = stash.begin(); it != stash.end(); it++)
        //     cout<<it->first<<" "<<it->second<<endl;
    }
}
