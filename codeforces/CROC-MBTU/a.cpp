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
    int n,tmp;
    cin>>n;
    vector<int> foo;
    int i=0;
    int curr=0, neg=0;
    while(i<n)
    {
        cin>>tmp;
        if(tmp>=0)
        curr++; else neg++, curr++;
        if(neg==3)
        {
            neg = 1;
            curr--;
            foo.push_back(curr);
            curr = 1;
        }
        i++;
    }
    foo.push_back(curr);
    cout<<foo.size()<<endl;
    for(int i=0;i<foo.size();i++)
        cout<<foo[i]<<' ';
    cout<<endl;

}
