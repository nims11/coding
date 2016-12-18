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
set<string> foo;
int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
    string str, tmp;
    int sum = 0, games = 0;
    while(cin>>str)
    {
        str.push_back('.');
        tmp="";
        for(int i=0;i<str.length();i++)
        {
            if(isalpha(str[i]))
            {
                tmp.push_back(tolower(str[i]));
            }else
            {
                if(tmp != "")
                {
                    if(tmp == "bullshit")
                    {
                        games++;
                        sum += foo.size();
                        foo.clear();
                    }else
                    {
                        foo.insert(tmp);
                    }
                    tmp = "";
                }
            }
        }
    }
    int x = GCD(sum, games);
    cout<<sum/x<<" / "<<games/x<<endl;
}
