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
    int n,m;
    in_I(n);
    in_I(m);
    string str1,str2;
    map<string, int> country_v, name_v;
    map<string, int>::iterator it, it3;
    map<string, string> name_country;
    map<string, string>::iterator it2;
    for(int i=0;i<n;i++)
    {
        cin>>str1>>str2;
        name_country[str1] = str2;
        country_v[str2] = 0;
        name_v[str1] = 0;
    }
    for(int i=0;i<m;i++)
    {
        cin>>str1;
        name_v[str1]++;
    }
    string w_name, w_country;int v_n = 0, v_c = 0;
    for(it=name_v.begin();it!=name_v.end();it++)
    {
        it2 = name_country.find(it->first);
        it3 = country_v.find(it2->second);
        it3->second += it->second;
        if(it3->second>v_c)
        {
            v_c = it3->second;
            w_country = it3->first;
        }else if(it3->second == v_c && it3->first<w_country)
            w_country = it3->first;

        if(it->second>v_n)
        {
            v_n = it->second;
            w_name = it->first;
        }


    }
    cout<<w_country<<endl<<w_name<<endl;
}
