#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector< vector <int> > vertices;
bool visited[10001]={0};
int max2[10001][2]={{0}};
int maxn=0;
int DFS(int n)
{
    visited[n]=true;
    for(int i=0;i<vertices[n].size();i++)
    {
        if(!visited[vertices[n][i]])
        {
            int x=DFS(vertices[n][i]);
            if(x>max2[n][0]){max2[n][1]=max2[n][0];max2[n][0]=x;}
            else if(max2[n][1]<x)max2[n][1]=x;
        }
    }
    int tmp=max2[n][0]+max2[n][1];
    if(tmp>maxn)
    maxn=tmp;
    return max2[n][0]+1;
}
int main()
{
	int n;
	cin>>n;
	vertices.reserve(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        vertices[x].push_back(y);
        vertices[y].push_back(x);
    }
    DFS(1);
    cout<<maxn<<endl;
	return 0;
}
