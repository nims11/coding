#include<iostream>
#include<vector>
using namespace std;
long long get_min(vector<long long> &x)
{
    long long min=10000;
    for(long long i=0;i<x.size();i++)
    if(x[i]<min)
    min=x[i];
    return min;
}
int main()
{
    long long n;
    while(cin>>n)
    {
        if(n!=0)
        {
            long long x;
            vector<long long>dim;
            for(long long i=0;i<3*n;i++)
            {
                cin>>x;
                dim.push_back(x);
            }
            x=get_min(dim);
            long long vol=x*x*x;
            long long count=0;
            for(int i=0;i<n;i++)
            {
                count+=(dim[3*i]*dim[3*i+1]*dim[3*i+2])/vol;
            }
            cout<<count<<endl;
        }
    }
    return 0;
}
