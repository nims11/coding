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
int arr[10001];
int am;
int BIT[10001];
int query(int idx, int n)
{
    int ret = 0;
    while(idx>0)
    {
        ret += BIT[idx];
        idx -= idx & -idx;
    }
    return ret;
}
void update(int idx, int n, int val)
{
    while(idx<=n)
    {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}
map<int, int> rev;
int getans(set<int> &s1, set<int> &s2){
    memset(BIT, 0, sizeof(BIT));
    set<int>::iterator it1, it2;
    int i = 0;
    int posdiff = abs((int)s1.size()-am);
    vector<int> x;
    for(it1 = s1.begin(); it1 != s1.end(); it1++, i++)
    {
        posdiff += abs(i-rev[*it1]);
        x.push_back(*it1);
//        cout<<*it1<<endl;
    }
    i = n-1;
    x.push_back(arr[am]);
    vector<int> y;
    for(it1 = s2.begin(); it1 != s2.end(); it1++,i--)
    {
        posdiff += abs(i-rev[*it1]);
        y.push_back(*it1);
    }
    for(int i = (int)y.size()-1;i>=0;i--)
        x.push_back(y[i]);
//    assert(posdiff%2 == 0);
    int inv = 0;
    map<int, int> foo;
    for(int i = 0;i<n;i++)
    {
//        cout<<x[i]<<endl;
        foo[x[i]] = i;
    }
    for(int i = 0;i<n;i++)
    {
//        cout<<foo[arr[i]]<<" "<<endl;
        inv += query(n,n) - query(foo[arr[i]]+1,n);
        update(foo[arr[i]]+1, n, 1);
    }

//    return posdiff/2;
    return inv;
}
int main()
{
    int z = 0;
    in_T{
        rev.clear();
        cin>>n;
        am = 0;
        z++;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            rev[arr[i]] = i;
            if(arr[i]>arr[am])
                am = i;
        }
        int ans = 1e9;
        for(int mask = 0; mask<(1<<n); mask++){
            set<int> s1, s2;
            set<int>::iterator it;
            for(int i = 0;i<n;i++){
                if(i!=am){
                    if(mask&(1<<i))
                        s1.insert(arr[i]);
                    else
                        s2.insert(arr[i]);

                    ans = min(ans, getans(s1, s2));
                }
            }
        }
        if(ans == 1e9)
            ans = 0;
        cout<<"Case #"<<z<<": "<<ans<<endl;
    }
}
