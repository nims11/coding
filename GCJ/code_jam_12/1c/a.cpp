#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n,x,y,start;
        cin>>n;
        vector< vector<int> > neigh(n+1);
        vector<bool> visited(n+1);
        for(int i=1;i<=n;i++)
        visited[i]=false;


        for(int i=1;i<=n;i++)
        {
            cin>>x;
            for(int j=0;j<x;j++)
            {
                cin>>y;
                neigh[i].push_back(y);
                //cout<<y<<endl;
            }
        }
        bool flag=false;
        for(int start=1;start<=n;start++)

        {
            stack<int> DFS;
        DFS.push(start);
        for(int i=1;i<=n;i++)
        visited[i]=false;
        visited[start]=true;
        while(!DFS.empty() && !flag)
        {
            int d=DFS.top();
            DFS.pop();
            for(int i=0;i<neigh[d].size();i++)
            {
                if(visited[neigh[d][i]])
                {
                    flag=true;
                    break;
                }else
                DFS.push(neigh[d][i]);
                visited[neigh[d][i]]=true;
            }
        }
        if(flag)
        break;
        }
        if(flag)
        cout<<"Case #"<<z+1<<": Yes\n";
        else
        cout<<"Case #"<<z+1<<": No\n";
    }
}
