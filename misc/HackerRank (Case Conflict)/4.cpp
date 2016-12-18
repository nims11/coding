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
int n;
int x;
vector<pair<int, int> > cnt;
int arr[100001];
int getans(int idx){
    int res = 1e9;
    int tmp = cnt[idx].second;
    queue<int> simu;
    for(int i = 0;i<tmp;i++)
        simu.push(1);

//    cout<<" "<<cnt[idx].first<<" ";
    idx--;
    int offset = 0;
    while(idx>=0 && cnt[idx+1].first == cnt[idx].first + 1){
//        cout<<cnt[idx].first<<" ";
       tmp = cnt[idx].second;
        int diff = tmp-(int)simu.size();
        if(diff<0){
        for(int i = 0;i<-diff;i++){
            res = min(res, offset+simu.front());
            simu.pop();
        }
        }else { 
            offset ++;
            for(int i = 0;i<diff;i++){
                simu.push(0);
            }
        }

        idx--;
   }
//   cout<<endl;
    while(!simu.empty()){
        res = min(res, offset+simu.front());
        simu.pop();
    }
    return res;
}
int main()
{
    in_T{
        cnt.clear();
        in_I(n);
        if(n == 0)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i = 0;i<n;i++){
            in_I(arr[i]);
        }
        sort(arr, arr+n);

        int idx = 1;
        int cur = 1;
        while(idx<=n){
            if(idx == n || arr[idx] != arr[idx-1]){
                cnt.push_back(make_pair(arr[idx-1], cur));
                cur = 0;
            }
            cur++;
            idx++;
        }
        int ans = 1e9;
        for(int i = 1;i<cnt.size();i++){
            if(cnt[i].first != cnt[i-1].first+1){
                ans = min(ans, getans(i-1));
            }
        }
        ans = min(ans, getans(cnt.size()-1));
        printf("%d\n", ans);
    }
}
