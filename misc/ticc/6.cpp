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
char str[10004];
int len = 0;
bool check(int l, int r){
    for(int i = 0;i<=len/2;i++){
        int L = i, R = len-L-1;
        if(L>=l && L<=r)
            L = l + (r-L);
        if(R>=l && R<=r)
            R = l + (r-R);
        if(str[L] != str[R])
            return false;
    }
    return true;
}
int main()
{
    in_S(str);
    len = strlen(str);
    for(int i = 0;i<len;i++){
        if(str[i] != str[len-i-1]){
            for(int j = i+1;j<len-i-1;j++){
                if(str[j] == str[len-i-1] && check(i, j)){
                    printf("Yes\n");
                    return 0;
                }
                if(str[j] == str[i] && check(j, len-i-1)){
                    printf("Yes\n");
                    return 0;
                }
            }
            printf("No\n");
            return 0;
        }
    }
}
