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
string teams[2];
struct evt{
    int time, num;
    char tm, card;
    friend bool operator<(const evt &a, const evt &b){
        return a.time<b.time;
    }
};
int foo[200][100];
int main()
{
    cin>>teams[0]>>teams[1];
    vector<evt> bar;
    in_T{
        evt tmp;
        cin>>tmp.time>>tmp.tm>>tmp.num>>tmp.card;
        bar.push_back(tmp);
    }
    sort(bar.begin(), bar.end());
    for(int i = 0;i<bar.size();i++){
        int prev = foo[bar[i].tm][bar[i].num];
        int cur = (foo[bar[i].tm][bar[i].num] += (bar[i].card=='r'?2:1));
        if(prev < 2 && cur >= 2)
            cout<<(teams[bar[i].tm=='a'?1:0])<<" "<<bar[i].num<<" "<<bar[i].time<<endl;
    }
}
