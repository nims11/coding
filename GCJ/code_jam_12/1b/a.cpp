#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        cout<<"Case #"<<z+1<<": ";
        long long n,x;
        long long sum=0;
        double y;
        vector<long long> J;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            J.push_back(x);
            sum+=x;
        }

        y=(sum*2)/double(n);
        double g=sum*2;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(J[i]>y)
            {
                count++;
                g-=J[i];
            }
        }
        y=g/double(n-count);
        for(int i=0;i<n;i++)
        {
            if(double(J[i])>y)
            {
                printf("0.000000 ");
            }else
            {
                printf("%.6lf ",((y-J[i])/sum)*100);
            }
        }
        cout<<endl;
    }
    return 0;
}
