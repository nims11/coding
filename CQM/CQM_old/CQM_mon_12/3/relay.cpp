/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int src,dest;
    while(scanf("%d%d\n",&src,&dest)!=EOF)
    {
        int n=0;
        int dist[1002][1002]={{0}},cost[1002];
        for(int i=0;i<1002;i++)
        cost[i]=1<<30;
        string str1,str2,str3;
        getline(cin,str1);
        getline(cin,str2);
        getline(cin,str3);
        int A[1002],B[1002],a,b;
        stringstream ss1(str1),ss2(str2),ss3(str3);
        while(ss1>>a)
        {
            ss2>>b;ss3>>dist[a][b];
            n++;
        }
        queue<int> BFS;
        string from[1002];
        BFS.push(src);
        cost[src]=0;
        bool bang=false;
        bool visited[1002]={0};
        l visited_from[1002][1002]={{0}};
        while(!BFS.empty())
        {
            int curr = BFS.front();BFS.pop();
//            cout<<"*"<<curr<<endl;
            for(int i=0;i<1002;i++)
            if(dist[curr][i])
            {
//                cout<<curr<<" "<<i<<" "<<cost[curr]<<" "<<cost[i]<<endl;
                if(cost[curr]+dist[curr][i] < cost[i])
                {
                    from[i]=from[curr];
                    from[i].push_back(curr+'0');
                    cost[i] = cost[curr]+dist[curr][i];
                    BFS.push(i);
                }
            }
        }
        if(cost[dest]==1<<30)cout<<"bigcrunch\n";
        else {
            cout<<cost[dest]<<" ";
            for(int i=0;i<from[dest].length();i++)
            cout<<from[dest][i]<<" ";
            cout<<dest<<endl;

            }
    }
}
