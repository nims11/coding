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
int N;
map<string, int> cityToId;
map<int, string> idToCity;
char str1[100],str2[100];
int tmp,curr,sum,start,x,y;
int deg_dif[5000], foo[5000], bar[5000];
int main()
{
    in_T
    {
        in_I(N);
        curr=0;
        sum = 0;
        for(int i=0;i<N;i++)
            deg_dif[i] = 0, foo[i] = -1;
        cityToId.clear();
        idToCity.clear();
        for(int i=0;i<N-1;i++)
        {
            scanf("%s %s %d$", str1, str2, &tmp);
            if(cityToId.find(str1)==cityToId.end())
            {
                idToCity[curr] = str1;
                cityToId[str1] = curr++;
            }
            if(cityToId.find(str2)==cityToId.end())
            {
                idToCity[curr] = str2;
                cityToId[str2] = curr++;
            }
            x = cityToId[str1];
            y = cityToId[str2];
            deg_dif[x]++;
            deg_dif[y]--;
            foo[x] = y;
            bar[cityToId[str2]] = tmp;
            sum += tmp;
        }
        for(int i=0;i<N;i++)
        {
            if(deg_dif[i] == 1)
            {
                start = i;
                break;
            }
        }
        while(foo[start]!=-1)
        {
            printf("%s %s %d$\n", idToCity[start].c_str(), idToCity[foo[start]].c_str(), bar[foo[start]]);
            start = foo[start];
        }
        printf("%d$\n",sum);
    }
}
