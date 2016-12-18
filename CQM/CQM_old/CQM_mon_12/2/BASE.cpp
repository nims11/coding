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
int base32_chr[300],base64_chr[300];int base32_int[300],base64_int[300];
vector<char> to_64(vector<char> bin)
{
    vector<char> ans;

    while(bin.size()%6)bin.push_back(0);
    for(int i=0;i<bin.size();i+=6)
    {
        int foo=0;
        for(int j=0;j<6;j++)
        {
            foo |= bin[i+j];
            foo<<=1;
        }
        foo>>=1;
        ans.push_back(base64_int[foo]);
    }
    return ans;
}
vector<char> to_bin(string base32)
{
    vector<char> ans;
    for(int i=0;i<base32.length();i++)
    {
        int foo=base32_chr[base32[i]];
        for(int k=1<<4;k>0;k=k>>1)
        {
            if(k&foo)ans.push_back(1);
            else ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    base32_chr['=']=base64_chr['=']=0;

    for(int i='A',j=0;i<='Z';i++,j++)
    {
        base32_chr[i]=base64_chr[i]=j;
        base32_int[j]=base64_int[j]=i;
    }
    for(int i='a',j=26;i<='z';i++,j++)
    {
        base64_chr[i]=j;
        base64_int[j]=i;
    }
    for(int i='0',j=52;i<='9';i++,j++)
    {
        base64_chr[i]=j;
        base64_int[j]=i;
    }
    for(int i='2',j=26;i<='7';i++,j++)
    {
        base32_chr[i]=j;
        base32_int[j]=i;
    }
    base64_chr['+']=62;base64_int[62]='+';
    base64_chr['/']=63;base64_int[63]='/';
    string str;
    while(getline(cin,str)){
        while(str[str.size()-1]=='=')str.erase(str.size()-1);
        for(int i=0;i<str.size();i++)
        str[i]=toupper(str[i]);
    vector<char> ans=to_bin(str);
    while(!ans[ans.size()-1])
    {
        if(ans.size()==1)break;
        ans.pop_back();
    }
//    while(ans.size()%24)
//    ans.push_back(0);

    vector<char> ans2=to_64(ans);
    for(int i=0;i<ans2.size();i++)
    cout<<ans2[i];
    int k=ans2.size();
    while(k==0 || k%4)
    {
        k++;
        cout<<'=';
    }
    cout<<endl;
    }
}
