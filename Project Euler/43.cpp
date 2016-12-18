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
vector<int> p = {1, 2, 3, 5, 7, 11, 13, 17};
bool isFoo(vector<int> &perm){
    for(int i = 1;i<p.size();i++){
        int x = 0;
        for(int j = i;j<i+3;j++)
            x = x*10 + perm[j];
        if(x%p[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    long long res = 0;
    vector<int> perm = {0,1,2,3,4,5,6,7,8,9};
    do{
        if(perm[0] == 0)
            continue;
        long long p = 0;
        for(int i:perm){
            p = p*10+i;
        }
        if(isFoo(perm))
            res += p;
    }while(next_permutation(perm.begin(), perm.end()));
    cout<<res<<endl;
}
