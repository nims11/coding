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
string str;
int main()
{
    int c = 0;
//    in_T
    int t;
    cin>>t;
    cin.ignore(100, '\n');
    while(t--)
    {
        c++;
        getline(cin, str);
        int lvl[30] = {0};
        lvl[0] = 1;
        int cur = 0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == '[')
            {
                lvl[++cur]++;
            }
            else if(str[i] == ']')
            {
                lvl[cur--]++;
            }
        }

        for(int i=0;i<29;i++)
            lvl[i] -= lvl[i+1]/2;

        int max_lvl;
        for(max_lvl=29;!lvl[max_lvl];max_lvl--);
        long long ans = 0;
        long long curr = 1;
        for(int i=max_lvl;i>=0;i--)
        {
            ans += curr*lvl[i];
            curr<<=1;
        }
        cout<<c<<" "<<ans<<endl;
    }
}
