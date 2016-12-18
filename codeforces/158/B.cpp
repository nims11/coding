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
vector<int> foo;
bool isdig(char c)
{
    return c>='0' && c<='9';
}
void gen_foo(string &str)
{
    for(int i=2;i<str.length()-7;i++)
    {
        if(str[i]=='-' && isdig(str[i-1]) && isdig(str[i-2]) && isdig(str[i+1]) && isdig(str[i+2]))
        {
            if(str[i+3]=='-' && isdig(str[i+4]) && isdig(str[i+5]) && isdig(str[i+6]) && isdig(str[i+7]))
            {
                foo.push_back(i);
//                cout<<i<<endl;
            }
        }
    }
}
int dy[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    string str;
    cin>>str;
//str = "777-444---21-12-2013-12-2013-12-2013---444-777";
    gen_foo(str);
    map<pair<int, pair<int, int> > , int> qwe;
    map<pair<int, pair<int, int> > , int>::iterator it;
    pair<int, pair<int, int> >  tmp, maax;
    int pre_max = 0;
    for(int i=0;i<foo.size();i++)
    {
        int idx = foo[i];
        int dd = (str[idx-2]-'0')*10+str[idx-1]-'0';
        int mm = (str[idx+1]-'0')*10+str[idx+2]-'0';
        int yyyy = (((str[idx+4]-'0')*10+str[idx+5]-'0')*10+str[idx+6]-'0')*10+str[idx+7]-'0';
//        cout<<dd<<" "<<mm<<" "<<yyyy<<endl;
        if(mm>0 && mm <13)
        {
            tmp.second.first = mm;
            if((dd>=1 && dd<=dy[mm]))
            {
                tmp.first = dd;
                if(yyyy>=2013 && yyyy<=2015)
                {
                    tmp.second.second = yyyy;
                    it = qwe.find(tmp);
                    if(it==qwe.end())
                    {
                        qwe[tmp] = 1;
                        if(pre_max==0)
                        {
                            pre_max = 1;
                            maax = tmp;
                        }
                    }else
                    {
                        it->second += 1;
                        if((it->second)>pre_max)
                        {
                            pre_max = it->second;
                            maax = tmp;
                        }
                    }
                }
            }
        }
    }
    cout<<((maax.first<10)?"0":"")<<maax.first<<"-"<<((maax.second.first<10)?"0":"")<<maax.second.first<<"-"<<maax.second.second<<endl;
}
