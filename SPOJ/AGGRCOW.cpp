//GQ
/*
Objective: given positions of points, assign k objects to those points such that the minimum distance between objects is maximum.
Find that value.

Solution: A very good application of binary search. Use binary search to go through the solutions and find the maximum possible solution.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long next_pos(vector<long long> &locations,long long curr,long long x)
{
long long d=locations[curr];
curr++;
        while(curr<locations.size())
        {
            if(locations[curr]-d>=x)
            return curr;
            curr++;
        }
        return -1;

}
bool exists(long long x,vector<long long> &locations,int c)
{
    long long curr=0;
    while(c>0 && curr!=-1)
    {
//        cout<<locations[curr]<<endl;
        c--;
        curr=next_pos(locations,curr,x);
    }
    if(c==0)
    return true;
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector<long long> locations;
        for(int i=0;i<n;i++)
        {
            long long l;cin>>l;locations.push_back(l);
        }
        sort(locations.begin(),locations.end());
        long long start=1,end=1+locations[locations.size()-1]-locations[0],mid;
        long long ans=0;
        while(start<end)
        {
            mid=(start+end)>>1;
            if(exists(mid,locations,c))
            {start=mid+1;}
            else
            {end=mid;}
        }
        cout<<start-!exists(start,locations,c)<<endl;
    }
}
