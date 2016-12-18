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
#include<set>
using namespace std;
int n,k;
int a,b,c,r;
long long tmp;
int main()
{
    int C = 0;
    in_T
    {
        C++;
        scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &r);
        tmp = a;
        int arr[k], arr2[k+1];
        set<int> rem;
        multiset<int> curr;
        multiset<int>::iterator it2;
        set<int>::iterator it;
        for(int i=0;i<=k;i++)
            rem.insert(i);
        arr[0] = tmp;
        curr.insert(arr[0]);
        if(arr[0]<=k)
        {
            it = rem.find(arr[0]);
            if(it!=rem.end())
            {
                rem.erase(it);
            }
        }
//        cout<<tmp<<endl;
        for(int i=1;i<k;i++)
        {
            tmp = (tmp*b+c)%r;
//            cin>>tmp;
//            cout<<tmp<<endl;
            arr[i] = tmp;
            curr.insert(arr[i]);
            if(arr[i]<=k)
            {
                it = rem.find(arr[i]);
                if(it!=rem.end())
                {
                    rem.erase(it);
                }
            }
        }
        for(int i=0;i<k;i++)
        {
            arr2[i] = *(rem.begin());
            rem.erase(rem.begin());
            curr.erase(curr.find(arr[i]));
            if(arr[i]<=k && curr.find(arr[i])==curr.end())
            {
                rem.insert(arr[i]);
            }
        }
        arr2[k]= *(rem.begin());
//        for(int i=0;i<=k;i++)
//            cout<<arr2[i]<<endl;

        printf("Case %d: %d\n", C, arr2[(n-k-1)%(k+1)]);
    }
}
