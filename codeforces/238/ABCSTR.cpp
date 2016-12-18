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
char str[1000011];
map<pair<int, int> , int> foo;
map<pair<int, int> , int>::iterator it;
int main()
{
    in_S(str);
    pair<int, int> cur = make_pair(0, 0);
    foo[cur] = 1;
    long long res = 0;
    for(int i = 0;str[i];i++){
        if(str[i] == 'A')cur.first++;
        else if(str[i] == 'B')cur.second++;
        else    cur.first--, cur.second--;
        it = foo.find(cur);
        if(it == foo.end()){
            foo[cur] = 1;
        }else{
            res += it->second;
            it->second++;
        }
    }
    printf("%lld\n", res);
}
