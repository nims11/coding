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
int main()
{
    string str;
    int n;
    cin>>str>>n;
    int a[26] = {0};
    for(int i = 0; i<str.length(); i++)
        a[str[i]-'a']++;
    for(int sol = 1; sol <= str.length(); sol++)
    {
        int x = 0;
        for(int i = 0; i<26; i++)
        {
            if(a[i])
                x += a[i]/sol + (a[i]%sol != 0);
        }
        if(x<=n)
        {
            string ans;
            for(int i = 0; i<26; i++)
            {
                if(a[i])
                {

                    int y = a[i]/sol + (a[i]%sol != 0);
                    while(y--)
                        ans.push_back('a'+i);
                }
            }
            while(ans.size() != n)
                ans.push_back('a');
            cout<<sol<<endl;
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
