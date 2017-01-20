#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
vector<int> pos[200001];
vector<int> order;
set<int> tmp;
int main(){
    int n;
    vector<int> arr;
    vector<int> val;
    in_I(n);
    for(int i = 0;i<n;i++){
        int x, y;
        in_I(x);
        in_I(y);
        arr.push_back(x);
        val.push_back(y);
        pos[x].push_back(y);
    }
    for(int i = n-1;i>=0;i--){
        int x = arr[i];
        if(tmp.find(x) == tmp.end()){
            order.push_back(x);
            tmp.insert(x);
        }
    }
    int q;
    in_I(q);
    while(q--){
        tmp.clear();
        int k,x;
        in_I(k);
        while(k--){
            in_I(x);
            tmp.insert(x);
        }
        int w1 = -1, w2 = -1;
        for(int i = 0;i<order.size() && (w1 < 0 || w2 < 0);i++){
            if(tmp.find(order[i]) == tmp.end()){
                if(w1 == -1)
                    w1 = order[i];
                else if(w2 == -1)
                    w2 = order[i];
            }
        }
        if(w1 == -1){
            printf("0 0\n");
            continue;
        }
        printf("%d ", w1);
        int last_w;
        if(w2 == -1){
            last_w = -1;
        }else
            last_w = pos[w2][pos[w2].size()-1];
        printf("%d\n", *lower_bound(pos[w1].begin(), pos[w1].end(), last_w));
    }
}
