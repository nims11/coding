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
        int N, M;
        in_I(N);
        in_I(M);
        vector<pair<int, int> > hikers;
        for(int i = 0;i<M;i++){
            int D, H, M;
            in_I(D);in_I(H);in_I(M);
            for(int j = M;j<M+H;j++)
                hikers.push_back(make_pair(D, j));
        }
        sort(hikers.begin(), hikers.end());
        int ans = 1;
        double v1 = 360/hikers[0].second;
        double v2 = 360/hikers[1].second;
        if(v1 < v2)
            swap(v1, v2), swap(hikers[0], hikers[1]);
        int d = (hikers[1].first - hikers[0].first);
        if(d < 0)
            d += 360;
        double t = d/double(v1-v2);
        double D = hikers[0].first + t*v1;
    }
}
