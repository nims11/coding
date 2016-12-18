#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        set <int> stations;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            stations.insert(x);
        }
        bool possible=true;
        int pre=0;
        for(set<int>::iterator i=stations.begin();i!=stations.end();i++)
        {
            if((*i)-pre>200)
            {
                possible=false;
                break;
            }
            pre=(*i);
        }
        set<int>::iterator i=stations.end();
        if(2*(1422-(*(--i)))>200)
        possible=false;
        if(possible)
        cout<<"POSSIBLE"<<endl;
        else
        cout<<"IMPOSSIBLE"<<endl;
        cin>>n;
    }
    return 0;
}
