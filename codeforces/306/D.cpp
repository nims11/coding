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
    int k;
    cin>>k;
    if(k % 2 == 0){
        cout<<"NO"<<endl;
        return 0;
    }
    if(k == 1){
        cout<<"YES\n2 1\n1 2\n";
        return 0;
    }
    cout<<"YES"<<endl;
    int g2_st = 2*k-1;
    vector<pair<int, int> > e;
    for(int i = 0;i<k-1;i++){
        e.push_back(make_pair(0, i+1));
        for(int j = 0;j<k-1;j++)
            e.push_back(make_pair(i+1, k+j));
        if(i%2 == 0)
            e.push_back(make_pair(k+i, k+i+1));
    }
    cout<<g2_st*2<<" "<<(1+2*e.size())<<endl;
    cout<<1<<" "<<g2_st+1<<endl;
    int chk[g2_st*2+1];
    memset(chk, 0, sizeof(chk));
    chk[g2_st+1]++;
    chk[1]++;
    for(int i = 0;i<e.size();i++){
        cout<<e[i].first+1<<" "<<e[i].second+1<<endl;
        cout<<e[i].first+g2_st+1<<" "<<e[i].second+g2_st+1<<endl;
        chk[e[i].first+1]++;
        chk[e[i].second+1]++;
        chk[e[i].first+g2_st+1]++;
        chk[e[i].second+g2_st+1]++;
    }
    for(int i = 1;i<=2*g2_st;i++){
        if(chk[i] != k){
            cout<<"*****"<<i<<"****"<<endl;
        }
    }
}
