#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
vector<vector<int>> ques;
int mini[1025];
        set<int> not_useful;
int main(){
    int n;
    in_I(n);
    int N = 1;
    while(N < n){
        N *= 2;
    }
    for(int i= 0;i<n;i++)
        mini[i] = 1e9+10;
    int cur_D = N;
    while(cur_D > 1){
        vector<int> q1, q2;
        for(int i = 0;i<cur_D/2;i++){
            for(int j = i;j<N;j+=cur_D){
                if(j >= 0 && j < n)
                    q1.push_back(j);
                if(N-j-1 >= 0 && N-j-1 < n)
                    q2.push_back(N-j-1);
            }
        }
        not_useful.clear();
        for(int x: q1){
            not_useful.insert(x);
        }
        printf("%d\n", q1.size());
        for(int x: q1){
            printf("%d ", x+1);
        }
            printf("\n");
        fflush(stdout);
        for(int i = 0;i<n;i++){
            int x;
            in_I(x);
            if(not_useful.find(i) == not_useful.end()){
                mini[i] = min(mini[i], x);
            }
        }
        not_useful.clear();
        for(int x: q2){
            not_useful.insert(x);
        }
        printf("%d\n", q2.size());
        for(int x: q2){
            printf("%d ", x+1);
        }
            printf("\n");
        fflush(stdout);
        for(int i = 0;i<n;i++){
            int x;
            in_I(x);
            if(not_useful.find(i) == not_useful.end()){
                mini[i] = min(mini[i], x);
            }
        }
        cur_D /= 2;
    }
    printf("-1\n");
    fflush(stdout);
    for(int i = 0;i<n;i++){
        printf("%d ", mini[i]);
    }
    printf("\n");
    fflush(stdout);
}
