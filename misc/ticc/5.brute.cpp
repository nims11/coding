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
long long arr[1000000];
int n;
int main()
{
    in_I(n);
    for(int i = 1;i<=n;i++){
        in_L(arr[i]);
    }
    int q,l,r; 
    char str[3];
    in_I(q);
    while(q--){
        scanf("%s %d %d", str, &l, &r);
        if(str[0] == 'O'){
            for(int i = l;i<=r;i++)
                if(arr[i]%2 == 0)
                    arr[i]++;
        }else if(str[0] == 'E'){
            for(int i = l;i<=r;i++)
                if(arr[i]%2 == 1)
                    arr[i]++;
        }else if(str[0] == 'I'){
            for(int i = l;i<=r;i++)
                arr[i]++;
        }else if(str[0] == 'M'){
            long long res = 0;
            for(int i = l;i<=r;i++)
                res += arr[i];
            cout<<res<<endl;
        }
//        trav(1, 1, n);
    }
}
