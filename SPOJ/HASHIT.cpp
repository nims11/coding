/*
 * Straightforward implementation
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int hash(string foo)
{
    int ans=0;
    for(int i=0;i<foo.length();i++)
    {
        ans=(ans+foo[i]*(i+1))%101;
    }
    return (ans*19)%101;
}
int main()
{
    in_T
    {
        vector<string> table(101);
        int n,count=0;string str,str2;
        vector<string>::iterator it;
        cin>>n;
        while(n--)
        {
            cin>>str;
            str2=str.substr(4);
            if(str2.length()==0)continue;
            int hash_key=hash(str2);
            if(str[0]=='A')
            {
                if(find(table.begin(),table.end(),str2)!=table.end())continue;
                int key=-1;
                for(int j=0;j<20;j++)
                {
                    int tmp=(hash_key+j*j+23*j)%101;
                    if(!table[tmp].length())
                    {
                        key=tmp;break;
                    }
                }
                if(key==-1)continue;
                table[key]=str2;
                count++;
            }else
            {
                it=find(table.begin(),table.end(),str2);
                if(it==table.end())
                continue;
                *it="";
                count--;
            }
        }
        cout<<count<<"\n";
        for(int i=0;i<101;i++)
        {
            if(table[i].length())
            cout<<i<<":"<<table[i]<<"\n";
        }
    }
}
