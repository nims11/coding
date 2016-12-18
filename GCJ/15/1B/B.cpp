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
int main()
{
    int z = 0;
    in_T{
        z++;
        int R, C, N;
        in_I(R);in_I(C);in_I(N);
        int ans = 1e9;
        for(int i = 0;i<(1<<(R*C));i++){
            if(__builtin_popcount(i) == N){
                vector<pair<int, int> > locs;
                for(int j = 0;j<R*C;j++){
                    if(i & (1<<j)){
                        int r = j/R;
                        int c = j%R;
                        // cout<<r<<" "<<c<<endl;
                        locs.push_back(make_pair(r, c));
                    }
                }
                int cur = 0;
                for(int j = 0;j<locs.size();j++)
                    for(int k = j+1;k<locs.size();k++){
                        if(abs(locs[j].first - locs[k].first) + abs(locs[j].second - locs[k].second) == 1)
                            cur++;
                    }
                ans = min(ans, cur);
            }
        }
        cout<<"Case #"<<z<<": "<<ans<<endl;
    }
}
