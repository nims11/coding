#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void DFS(vector <vector<int> > &vertices,int n)
{
	stack <int> STACK,PARENT;
	int count=0;
	vector<bool> visited;
	for(int i=0;i<n+1;i++)
		visited.push_back(false);
	visited[1]=true;
	count++;
	STACK.push(1);
	PARENT.push(0);
	while(!STACK.empty() && count!=0)
	{
		int x=STACK.top();
		STACK.pop();
		int y=PARENT.top();
		PARENT.pop();
		for(int i=0;i<vertices[x].size();i++)
		{
			if(!visited[vertices[x][i]])
			{
				visited[vertices[x][i]]=true;
				count++;
				STACK.push(vertices[x][i]);
				PARENT.push(x);
			}else
			{
				if(vertices[x][i]!=y)
				{count=0;
				break;}
			}
		}
	}

	if(count==n)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
int main()
{
	int n,m;
	cin>>n>>m;
	if(n-m!=1)
		cout<<"NO"<<endl;
	if(n==1 && m==0)
		cout<<"NO"<<endl;
	else
	{
		vector< vector <int> > vertices(n+1);
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			vertices[x].push_back(y);
			vertices[y].push_back(x);
		}
		DFS(vertices,n);
	}
	return 0;
}
