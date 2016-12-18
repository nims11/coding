#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        vector <string>ans;
        string tmp;int max=0;
        int x;
        for(int i=0;i<10;i++)
        {
            cin>>tmp>>x;
            if(x==max)
            ans.push_back(tmp);
            else if(x>max)
            {
                max=x;
                ans.clear();
                ans.push_back(tmp);
            }
        }
        cout<<"Case #"<<z<<":\n";
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    }
}
