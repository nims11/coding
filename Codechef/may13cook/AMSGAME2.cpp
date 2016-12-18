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
map<int, long long> nums;
map<int, long long>::iterator it, it2;
int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}

int n,x;
int main()
{
    in_T
    {
        in_I(n);
        nums.clear();
        for(int i=0;i<n;i++)
        {
            in_I(x);
            map<int, long long> tmp;
            for(it = nums.begin(); it!=nums.end(); it++)
            {
                int y = GCD(it->first, x);
                it2 = tmp.find(y);
                if(it2 == tmp.end())
                {
                    tmp[y] = it->second;
                }else
                {
                    it2->second += it->second;
                }
            }
            it2 = tmp.find(x);
            if(it2 == nums.end())
            {
                tmp[x] = 1;
            }else
                tmp[x] += 1;

            for(it2 = tmp.begin(); it2 != tmp.end(); it2++)
            {
                it = nums.find(it2->first);
                if(it!=nums.end())
                {
                    it->second += it2->second;
                }else
                    nums[it2->first] = it2->second;
            }

        }
        printf("%lld\n", nums[1]);
    }
}
