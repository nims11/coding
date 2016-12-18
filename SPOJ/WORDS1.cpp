/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<string>
#include<cstdio>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define P(a) printf("*%d\n",a)
#define in_S(a) scanf("%s",&a)

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
void connec(int graph[26][26],int i)
{
    for(int j=0;j<26;j++)
    {
        if(graph[i][j])
        {graph[i][j]=0;
        connec(graph,j);}
    }
}
int main()
{
    in_T
    {
        int n;
        in_I(n);
        int in[26]={0};
        int out[26]={0};
        int graph[26][26]={0};

        std::string tmp;
        int c=0;
        for(int i=0;i<n;i++)
        {
            std::cin>>tmp;
            int a=tmp[0]-'a',b=tmp[tmp.length()-1]-'a';
            out[a]++;
            in[b]++;
            graph[a][b]=1;
            c=a;
        }
        bool flag=true;
        int c_1=-1,c_n1=-1;
        for(int i=0;i<26;i++)
        {
            int x=in[i]-out[i];
            if(x==-1)
            {
                if(c_1!=-1){flag=false;break;}
                c_1=i;
            }else if (x==1)
            {
                if(c_n1!=-1){flag=false;break;}
                c_n1=i;
            }else if(x!=0)
            {
                flag=false;break;
            }
        }
        if(flag)
        {
            if(c_1==-1)c_1=c;
            connec(graph,c_1);
            for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
            if(graph[i][j]){flag=false;}
        }
        if(flag)
        printf("Ordering is possible.\n");
        else
        printf("The door cannot be opened.\n");
    }
    return 0;
}
