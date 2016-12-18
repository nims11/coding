#include<cstdio>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,int> tab;
    map<string,int>::iterator it;
    int t;
    scanf("%d",&t);
    char acc[40];
    while(t--)
    {
        tab.clear();
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            gets(acc);
            acc[32]=0;
            tab[acc]++;
        }
        for(it=tab.begin();it!=tab.end();it++)
        {
            printf("%s %d\n",it->first.c_str(),it->second);
        }
        printf("\n");

    }
}
