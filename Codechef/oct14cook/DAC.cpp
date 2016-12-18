#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
#include <cassert>
#include <queue>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
vector <int> A;
set <int> aset;
map <int,string> ans_of;
void make_fibo(int prev,int curr,string ans)
{
    if(curr > 100000000)
        return;
    if(aset.find(curr)!=aset.end())
        return;
    aset.insert(curr);
    ans_of[curr]=ans;
    make_fibo(curr,prev+curr,ans+'.');
    make_fibo(curr,2*curr,ans+"#...");

}
int main()
{
    aset.insert(0);
    aset.insert(1);
    ans_of[0]="#";
    ans_of[1]=".";
    make_fibo(1,2,"...");
    for(set <int>::iterator itr=aset.begin();itr!=aset.end();itr++)
    {
        A.push_back((*itr));

    }
    int t,sz=A.size();
    scanf("%d",&t);
    while(t--)
    {
        int l,r,n;
        scanf("%d %d %d",&l,&r,&n);
        int lo=0,hi=sz-1,mid;
        if(A[lo]<=l && A[hi]>=l)
        {
            while(lo<hi)
            {
                mid=(lo+hi)/2;
                if(A[mid]>=l)
                    hi=mid;
                else
                    lo=mid+1;

            }
            if(hi+n-1<sz && A[hi+n-1]<=r)
                cout<<A[hi+n-1]<<" "<<ans_of[A[hi+n-1]]<<"\n";
            else
                cout<<"-1\n";

        }
        else
            cout<<"-1\n";

    }
    return 0;

}
