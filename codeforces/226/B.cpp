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
    string str;
    cin>>str;
    vector<int> pos;
    int cur = str.find("bear");
    while(cur != string::npos){
        pos.push_back(cur);
        cur = str.find("bear", cur+1);
    }
    if(pos.size() == 0){
        cout<<0<<endl;
    }else{
        int res = 0;
        int pre = 0;
        for(int i = 0;i<str.size();i++){
            if(pre != pos.size())
            if(i == pos[pre]+3)
                pre++;
            if(pre != 0)
                res += pos[pre-1]+1;
        }
        cout<<res<<endl;
    }
}
