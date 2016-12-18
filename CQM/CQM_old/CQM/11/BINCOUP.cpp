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

using namespace std;
int main()
{
    in_T
    {
        string str;
        cin>>str;
        long long ans = 0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '1')
            {
                int end = i;
                while(str[end] == '1' && end<str.size())
                    end++;
                end--;
                ans += (long long)((end+1)*(end))/2;
                i = end+1;
            }
        }
        cout<<(long long)(str.size()*(str.size()+1))/2 - ans<<endl;
    }
}
