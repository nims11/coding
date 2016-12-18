#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2==1)
        {
            cout<<1<<endl;
            long long x;
            for(int i=0;i<n;i++)
            cin>>x>>x;
        }
        else
        {
            vector <long long> Xi,Yi;
            make_heap(Xi.begin(),Xi.end());
            make_heap(Yi.begin(),Yi.end());
            long long x,y;
            for(int i=0;i<n;i++)
            {
                cin>>x>>y;
                Xi.push_back(x);
                push_heap(Xi.begin(),Xi.end());
                Yi.push_back(y);
                push_heap(Yi.begin(),Yi.end());
            }
            sort_heap(Xi.begin(),Xi.end());
            sort_heap(Yi.begin(),Yi.end());
            cout<<(1+Xi[n/2]-Xi[n/2-1])*(1+Yi[n/2]-Yi[n/2-1])<<endl;
        }

    }
    return 0;
}
