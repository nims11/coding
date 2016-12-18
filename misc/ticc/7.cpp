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
int arr[1009];
int N,M;
int main()
{
    in_T{
        in_I(N);in_I(M);
        set<int> uniqSet;
        map<int, int> cnt;
        for(int i = 0;i<N;i++){
            in_I(arr[i]);
            uniqSet.insert(arr[i]);
            if(cnt.find(arr[i]) == cnt.end())
                cnt[arr[i]] = 1;
            else
                cnt[arr[i]]++;
        }
        long long res = 0;
        sort(arr, arr+N);
        set<pair<int, int> > foo;
        int uniqArr[uniqSet.size()];
        int xxx = 0;
        for(set<int>::iterator it = uniqSet.begin(); it != uniqSet.end(); it++){
            uniqArr[xxx++] = *it;
            if(3*(*it) <= M && cnt[*it] >= 3)
                res++;
        }

        int uniqArrSize = uniqSet.size();
        for(int i = 0;i<uniqArrSize;i++){
            int cursum = 2*uniqArr[i];
            if(cnt[uniqArr[i]] >= 2){
                int l = 0, r = upper_bound(uniqArr, uniqArr+uniqArrSize, M-cursum)-uniqArr;
                res += r-l;
                if(3*uniqArr[i] <= M)
                    res--;
            }

            for(int j = i+1;j<uniqArrSize && uniqArr[i]+uniqArr[j]<=M;j++){
                cursum = uniqArr[i]+uniqArr[j];
                int l = j+1;
                int r = upper_bound(uniqArr, uniqArr+uniqArrSize, M-cursum)-uniqArr;
                if(l<r)
                    res += r-l;
            }
        }

        printf("%lld\n", res);
    }
}
