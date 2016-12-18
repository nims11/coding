/*
ID: nimeshg1
PROG: calfflac
LANG: C++
*/
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
#include<fstream>
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
#include<cstring>
using namespace std;
ifstream fin("calfflac.in");
ofstream fout("calfflac.out");
vector<int> pos;
char str[20000],str2[20000];
int isPalin(int a,int b)
{
    int ret = 0;
    int start=a, end = b;
    while(start<=end)
    {
        if(str[pos[start]]==str[pos[end]])
        {
            if(start==end)
                ret++;
            else
                ret +=2;
            start++;
            end--;
        }else
        return -1;
    }
    return b-a+1;
}
int main()
{
    fin.read(str,20000);
    cout<<str<<endl;
    strcpy(str2,str);
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        str[i] = tolower(str[i]);
        if(isalpha(str[i]))
            pos.push_back(i);
    }
    int curr=0,start,end;
    for(int i=0;i<pos.size();i++)
    {
        for(int j=i+curr;j<pos.size() && pos[j]<pos[i]+2000;j++)
        {
            int foo = isPalin(i,j);
            if(foo>curr)
            {
                curr = foo;
                start = pos[i];
                end = pos[j];
            }
        }
    }
    fout<<curr<<endl;
    str2[end+1] = 0;
    fout<<(str2+start)<<endl;
}
