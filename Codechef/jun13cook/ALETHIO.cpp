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
inline bool is_dig(char ch)
{
    return (ch>='0' && ch<='9');
}
char str[1003];
int main()
{
    in_S(str);
    int len = strlen(str);
    int st = 0, end = 0;
    string ans = "";
    ans.push_back(is_dig(str[0])?str[0]:'9');
    int cur = -1;
    while(st<len)
    {
        while(st<len && str[st] == '0')st++;
        if(st == len)
            break;
        end = st;
        cur = -1;
        while(end<len)
        {
            if(!is_dig(str[end]))
            {
                if(cur == -1)
                    cur = end;
                else
                    break;
            }
            end++;
        }
        end--;
//        cout<<st<<" "<<end<<endl;
        if(end-st+1 > ans.size())
        {
            ans = "";
            for(int i=st;i<=end;i++)
                if(i == cur)
                    ans.push_back('9');
                else
                    ans.push_back(str[i]);
        }else if(end-st+1 == ans.size())
        {
            string ans2 = "";
            for(int i=st;i<=end;i++)
                if(i == cur)
                    ans2.push_back('9');
                else
                    ans2.push_back(str[i]);
            ans = max(ans, ans2);
        }
        if(cur == -1)
            st = end+1;
        else
            st = cur+1;
    }
    cout<<ans<<endl;
}
