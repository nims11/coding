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
int N, X;
int files[100000];
bool foo(int n){
    if(n*2<N)
        return false;
    int bins[n];
    int j = 0;
    for(int i = N-1;i>=N-n;i--,j++)
        bins[j] = files[i];
    for(int i = 0;i<N-n;i++){
        bins[i] += files[i];
    }
    for(int i = 0;i<n;i++)
        if(bins[i]>X)
        return false;
    return true;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cin>>N>>X;

        for(int i = 0;i<N;i++)
            cin>>files[i];
        sort(files, files+N);
        int end = 0;
        int a = 0, b = N-1;
        while(a<=b){
            if(files[a]+files[b]<=X)
                end++, a++, b--;
            else
                end++, b--;
        }
//        int st = 1, end = N;
//        while(st<end){
//            int mid = (st+end)/2;
//            if(foo(mid)){
//                end = mid;
//            }else
//                st = mid+1;
//        }
        cout<<"Case #"<<z<<": "<<end<<endl;
    }
}
