/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int t;
    in_I(t);
    string str;
    vector<string> cases(t);
    for(int z=0;z<t;z++)
    {
        cases[z]="";
        for(int k=0;k<t;k++){
        cin>>str;
        if(str=="YES")cases[z].push_back('1');
        else cases[z].push_back('0');
        }
    }
    for(int i=0;i<t;i++)
    {
        bool flag=true;
        string ans = cases[i];
        for(int j=0;j<t;j++)
        {
            if(ans==cases[j])
            {
                if(ans[j]=='1')
                continue;
                else
                {
                    flag=false;
                    break;
                }
            }else
            {
                if(ans[j]=='1')
                {flag=false;break;}
            }
        }
        if(flag)
        {
            for(int a=0;a<t;a++)
            {
                if(ans[a]=='1')
                cout<<"YES\n";
                else
                cout<<"NO\n";
            }
            return 0;
        }
    }
    for(int i=0;i<t;i++)
    cout<<"NO\n";

}
