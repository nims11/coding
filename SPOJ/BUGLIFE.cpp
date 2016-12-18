//GQ
/*
 * Construct a graph out of it. Graph Colouring with BFS. Check for contradictions
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
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
vector<int> neighbors[3000];int color[3000];
int n_b,n_i,a,b;
bool visited[3000];
bool BFS(int start)
{
	queue<int> foo;
	foo.push(start);
	color[start]=1;
	while(!foo.empty())
	{
		int curr=foo.front();
		visited[curr]=true;
		foo.pop();
		for(int i=0;i<neighbors[curr].size();i++)
		{
			if(color[neighbors[curr][i]]!=0){
				if(color[curr]==color[neighbors[curr][i]])
				return false;
			}else
				color[neighbors[curr][i]]=color[curr]*-1;
			if(!visited[neighbors[curr][i]])
				foo.push(neighbors[curr][i]);
		}
	}
	return true;
}
bool is_suspicious()
{
	for(int i=1;i<=n_b;i++)
		if(!visited[i] && !BFS(i))
			return false;
	return true;
}
int main()
{
	int t;
	in_I(t);
	for(int z=1;z<=t;z++)
	{
		in_I(n_b);in_I(n_i);
		for(int i=1;i<=n_b;i++)
		{
			neighbors[i].clear();
			visited[i]=false;
			color[i]=0;
		}
		for(int i=0;i<n_i;i++)
		{
			in_I(a);in_I(b);
			neighbors[a].push_back(b);
			neighbors[b].push_back(a);
		}
		if(is_suspicious())
			cout<<"Scenario #"<<z<<":\n"<<"No suspicious bugs found!\n";
		else
			cout<<"Scenario #"<<z<<":\n"<<"Suspicious bugs found!\n";

	}
}
