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
    int n, x;
    in_I(n);
    string str1, str2;
    char str[20];
    long long pt1 = 0, pt2 = 0;
    vector<int> pts1, pts2;
    for(int i = 0;i<n;i++){
        in_I(x);
        if(x>0)
            pt1 += x;
        else
            pt2 -= x;

        if(x>0)
            pts1.push_back(pt1);
        else
            pts2.push_back(pt2);
    }
    if(pt1 != pt2){
        printf(pt1>pt2?"first\n":"second\n");
        return 0;
    }
    int res = 0;
    for(int i = 0;i<min(pts1.size(), pts2.size());i++){
        if(pts1[i] != pts2[i]){
            res = pts1[i]-pts2[i];
            break;

    }}
    if(res == 0){
        if(pts1.size() > pts2.size())
            res = -1;
        else if (pts1.size() < pts2.size())
            res = 1;
    }
    if(res == 0)
        printf(x>0?"first":"second");
    else if(res < 0)
        printf("second");
    else
        printf("first");
    newline;
}
