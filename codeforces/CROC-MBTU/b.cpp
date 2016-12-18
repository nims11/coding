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
        int curr=0;
        vector<string> ans;
        while(curr<str.length())
        {
            vector<char> hex;
            while(str[curr]!=':' && curr<str.length())
            {
                hex.push_back(str[curr]);
                curr++;
            }
            if(hex.size()==0)
            {
                ans.push_back("x");
                while(str[curr]==':' && curr<str.length())curr++;
            }else
            {
                string tmp;
                for(int i=0;i<4-hex.size();i++)
                tmp.push_back('0');
                for(int i=0;i<hex.size();i++)
                tmp.push_back(hex[i]);
                ans.push_back(tmp);
            }

            if(str[curr]==':')
            curr++;
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=="x")
            {
                for(int j=0;j<9-ans.size();j++)
                {
                    cout<<"0000";
                    if(i+j!=7)cout<<":";
                }
            }else
            {
                cout<<ans[i];
                if(i!=ans.size()-1)cout<<":";
            }
        }
        cout<<endl;
    }
}
