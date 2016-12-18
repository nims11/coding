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
pair<string, string> getans(string str)
{
    string dir, n;
    int i =0;
    while(str[i] != ' ')
    {
        dir.push_back(str[i]);
        i++;
    }
    i+=4;
    for(;i<str.length();i++)
        n.push_back(str[i]);
    return make_pair(dir, n);
}
int main()
{
    in_T
    {
        int n;
        scanf("%d\n", &n);
        string str[n];
        for(int i=0;i<n;i++)
        {
            getline(cin, str[i]);
        }
        vector<string> foo;
        for(int i=0;i<n;i++)
        {
            pair<string, string> bar = getans(str[i]);
            foo.push_back(bar.first);
            foo.push_back(bar.second);
        }
        cout<<"Begin on ";
        for(int i=foo.size()-1;i>0;i--)
        {
            if(i%2)
            {
                cout<<foo[i]<<endl;
            }else
            {
                if(foo[i][0]=='L')
                    cout<<"Right on ";
                else
                    cout<<"Left on ";
            }
        }
        newline;
    }
}
