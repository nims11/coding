#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()
{
    int n,k,x;
    map<int,bool> nums;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        nums[x]=true;
    }
    int count=0;
    for(map<int,bool>::iterator i=nums.begin();i!=nums.end();i++)
    {
        if(nums.find((*i).first+k)!=nums.end())
        count++;
    }
    cout<<count<<endl;

    return 0;
}
