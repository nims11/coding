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
int main()
{
    in_T
    {
        int n,k;
        in_I(n);
        in_I(k);
        vector<int> digs;
        while(n)
        {
            digs.push_back(n%10);
            n/=10;
        }
        reverse(digs.begin(), digs.end());
        for(int i=0;i<digs.size() && k;i++)
        {
            int maxi = digs[i];
            int idx = i;
            for(int j=i+1;j<digs.size();j++)
            {
                if(digs[j]>maxi)
                {
                    maxi = digs[j];
                    idx = j;
                }
            }
            if(idx!=i)
            {
                k--;
                int tmp = digs[i];
                digs[i] = digs[idx];
                digs[idx] = tmp;
            }
        }
        bool flag = true;
        if(k)
        {
            for(int i=0;i<digs.size()-1;i++)
            if(digs[i] == digs[i+1])
            {
                k = 0;
                break;
            }
        }
        if(k)
        {
            if(digs.size() == 1 || (digs.size() == 2 && digs[1] == 0))
                flag = false;
            else
            {
                if(k&1)
                {
                    int tmp = digs[digs.size()-1];
                    digs[digs.size()-1] = digs[digs.size()-2];
                    digs[digs.size()-2] = tmp;
                }
            }
        }
        if(!flag)
            printf("-1");
        else
            for(int i=0;i<digs.size();i++)
            printf("%d", digs[i]);
        newline;
    }
}
