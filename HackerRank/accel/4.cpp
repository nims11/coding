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
vector<int> xx;
int main()
{
    for(int i = 1;i*i<=1000000000;i++)
        xx.push_back(i*i);
    in_T{
        int N;
        in_I(N);
        int cnt = upper_bound(xx.begin(), xx.end(), N) - xx.begin();
        cout<<cnt<<endl;
    }
}
