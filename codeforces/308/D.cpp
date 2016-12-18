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
map<pair<int, int>, int> sinvals[2001];
int GCD(int a,int b)
{
    if(a == 0 && b == 0)
        return 1;
    if(a == 0)return b;
    if(b == 0)return a;
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
    int n;
    in_I(n);
    vector<pair<int, int> > pt;
    for(int i = 0;i<n;i++){
        int x, y;
        in_I(x);in_I(y);
        pt.push_back(make_pair(x, y));
    }
    sort(pt.begin(), pt.end());
    long long cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            pair<int, int> sinval = make_pair(pt[i].second - pt[j].second, pt[i].first - pt[j].first);
            int gcd = GCD(abs(sinval.first), abs(sinval.second));
            sinval.first /= gcd;
            sinval.second /= gcd;
            if(sinvals[j].find(sinval) != sinvals[j].end())
                cnt+=sinvals[j][sinval];
            if(sinvals[i].find(sinval) == sinvals[i].end())
                sinvals[i][sinval] = 1;
            else
                sinvals[i][sinval] += 1;
        }
    }
    cnt = n*1LL*(n-1)*1LL*(n-2)/6 - cnt;
    cout<<cnt<<endl;
}
