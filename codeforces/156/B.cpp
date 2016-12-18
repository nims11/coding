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
#include<list>
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
    cin>>str;
    list<char> foo;
    list<char>::iterator it1, it2, tmp;
    bool to = true;
    for(int i=0;i<str.length();i++)
        foo.push_back(str[i]);
    it2 = foo.begin();
    it1 = it2++;
    while(it2!=foo.end())
    {
        if(*it2 != *it1)
        {
            if(*it1 == 'y')
            {
                *it1 = 'x';
                *it2 = 'y';
                if(it1!=foo.begin())
                    it1--, it2--;
            }else
            {
                if(it1==foo.begin())
                    to = false;
                else {tmp = it1;tmp--;}
                foo.erase(it1);
                foo.erase(it2);
                if(!to)
                    tmp = foo.begin();
                it1 = tmp;
                it2 = ++tmp;
            }
        }
        else it1++, it2++;
    }
    for(it1 = foo.begin();it1!=foo.end();it1++)
        printf("%c", *it1);
    newline;
}
