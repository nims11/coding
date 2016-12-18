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
#include<fstream>
#include<set>
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

int a[9][9]= { {3,3,3,3,3,2,3,2,0},
               {2,3,2,3,2,3,1,0,1},
               {3,3,3,2,3,3,0,2,3},
               {2,3,1,3,2,0,2,3,1},
               {2,3,2,3,1,3,2,3,2},
               {1,3,2,0,2,3,1,3,2},
               {3,2,0,3,3,2,3,3,3},
               {1,0,1,3,2,3,2,3,2},
               {0,2,3,2,3,3,3,3,3} };

int moves[9] = {
1|(1<<3)|(1<<9)|(1<<12),
1|(1<<3)|(1<<6),
(1<<3)|(1<<6)|(1<<12)|(1<<15),
1|(1<<9)|(1<<18),
(1<<3)|(1<<9)|(1<<12)|(1<<15)|(1<<21),
(1<<6)|(1<<15)|(1<<24),
(1<<9)|(1<<12)|(1<<18)|(1<<21),
(1<<18)|(1<<21)|(1<<24),
(1<<12)|(1<<15)|(1<<21)|(1<<24),
};
int main()
{
    int tmp;
    int cnt[9] = {0};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
    {
        in_I(tmp);
        int k = 0;
        while(tmp!=0)
        {
            tmp = (tmp+1)%4;
            k++;
        }
        for(int l=0;l<9;l++)
            cnt[l] += k*a[i*3+j][l];
    }
    for(int i=0;i<9;i++)
        cnt[i]%=4;
    vector<int> ans;
    for(int i=0;i<9;i++)
        for(int j=0;j<cnt[i];j++)ans.push_back(i+1);
    for(int i=0;i<ans.size();i++)
    {
        if(i == ans.size()-1)
            cout<<ans[i]<<endl;
        else
            cout<<ans[i]<<" ";
    }
//    int cnt2[9] = {0};
//    for(int i=0;i<9;i++)
//    {
//        tmp = modes[i];
//        for(int j=0;tmp;j++, tmp>>=3)
//        {
//            if(tmp&1)
//                cnt2[j] += cnt[i];
//        }
//    }
//    int ans = 0;
//    for(int i=0;i<9;i++)
//        ans = (ans+cnt2[i])%4
}
