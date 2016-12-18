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
int main()
{
    int n;
    cin>>n;
    vector<int> neg, pos, zer;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x<0)
            neg.push_back(x);
        else if(x>0)
            pos.push_back(x);
        else
            zer.push_back(x);
    }
    vector<int> set1;
    if(neg.size()%2 == 0)
    {
        for(int i=0;i<neg.size()-1;i++)
            set1.push_back(neg[i]);

        zer.push_back(neg[neg.size()-1]);
    }
    else
        for(int i=0;i<neg.size();i++)
            set1.push_back(neg[i]);
    if(pos.size() == 0)
    {
        pos.push_back(set1[set1.size()-1]);
        set1.pop_back();
        pos.push_back(set1[set1.size()-1]);
        set1.pop_back();
    }
    cout<<set1.size()<<" ";
    for(int i=0;i<set1.size();i++)
        cout<<set1[i]<<" ";
    cout<<endl;
    cout<<pos.size()<<" ";
    for(int i=0;i<pos.size();i++)
        cout<<pos[i]<<" ";
    cout<<endl;
    cout<<zer.size()<<" ";
    for(int i=0;i<zer.size();i++)
        cout<<zer[i]<<" ";
    cout<<endl;
}
