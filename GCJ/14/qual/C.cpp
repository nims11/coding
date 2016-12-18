/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int z = 0;
    in_T{
        z++;
        int N;
        in_I(N);
        double naomi[1001], ken[1001];
        vector<pair<double, int> > all;
        for(int i = 0;i<N;i++)
        {
            in_F(naomi[i]);
            all.push_back(make_pair(naomi[i], 0));
        }
        for(int i = 0;i<N;i++)
        {
            in_F(ken[i]);
            all.push_back(make_pair(ken[i], 1));
        }
        sort(all.begin(), all.end());
        int score = 0, ns = all.size()-1, score2 = N;
        for(int i = all.size()-1;i>=0;i--){
//            cout<<all[i].second<<" ";
            if(all[i].second == 0){
                if(ns>i)ns = i;
                while(ns >= 0 && all[ns].second != 1)ns--;
                if(ns >= 0)
                {
                    ns--, score++;
//                    cout<<"*"<<ns<<" ";
                }
            }
        }
        ns = all.size()-1;
        for(int i = all.size()-1;i>=0;i--){
//            cout<<all[i].second<<" ";
            if(all[i].second == 1){
                if(ns>i)ns = i;
                while(ns >= 0 && all[ns].second != 0)ns--;
                if(ns >= 0)
                {
                    ns--, score2--;
//                    cout<<"*"<<ns<<" ";
                }
            }
        }
//        cout<<endl;
        cout<<"Case #"<<z<<": "<<score<<" "<<score2<<endl;
    }
}
