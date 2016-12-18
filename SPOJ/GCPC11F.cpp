/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t),cin.ignore(1);t--;)
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
    in_T
    {
        getline(cin, str);
        pair<int, int> foo[26];
        for(int i=0;i<26;i++)
            foo[i] = make_pair(0,i);
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!=' ')
            foo[str[i]-'A'].first++;
        }
        sort(foo, foo+26);
        if(foo[25].first == foo[24].first)
        {
            cout<<"NOT POSSIBLE\n";
        }else
        {
            int k = foo[25].second - 4;
            if(k<0) k = 26+k;
            cout<<k<<" ";
            for(int i=0;i<str.length();i++)
            {
                if(str[i]==' ')
                    cout<<' ';
                else
                    cout<<char('A'+(26+(str[i]-'A')-k)%26);
            }
            cout<<endl;
        }
    }
}
