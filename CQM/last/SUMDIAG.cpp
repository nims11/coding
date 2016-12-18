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
long long res[1000001];
int main()
{
    res[1] = 1;
    int curN = 3;
    pair<int, int> coord = make_pair(1, 0);
    int inX = 0, inY = 1;
    for(int i = 2;i<=1000000;i++){
//        if(i<=25)
//        cout<<i<<": "<<coord.first<<" "<<coord.second<<endl;
        if(coord.first == curN/2 && coord.second == curN/2){
            res[curN] += i;
            inX = -1, inY = 0;
        }else if(coord.first == -curN/2 && coord.second == curN/2){
            res[curN] += i;
            inX = 0, inY = -1;
        }else if(coord.first == -curN/2 && coord.second == -curN/2){
            res[curN] += i;
            inX = 1, inY = 0;
        }else if(coord.first == curN/2 && coord.second == -curN/2){
            res[curN] += i;
            coord.first++;
            curN += 2;
            inX = 0, inY = 1;
            continue;
        }
        coord.first += inX, coord.second += inY;
    }
    for(int i = 3;i<=1000000;i++)
        res[i] += res[i-2];
    in_T{
        int N;
    in_I(N);
    printf("%lld\n", res[N]);
    }
}
