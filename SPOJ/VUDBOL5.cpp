#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long unsigned N,x,A[2];
    while(cin>>N)
    {
        if(N==0)
        break;
        bool flag=false;
        vector <long long unsigned> nums;
        for(int i=0;i<4;i++)
        {
            cin>>x;
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<3;i++)
        if(nums[i]==nums[i+1])
        {
            x=nums[i];
            flag=true;
            break;
        }
        if(!flag)
        {
            cout<<"Impossible\n";
            continue;
        }
        flag=false;
        int count=0;
        for(int i=0;i<4;i++)
        if(nums[i]!=x)
        A[count++]=nums[i];

        if(count==0)
        A[0]=A[1]=x;
        if(count==1)
        A[1]=x;

        long long unsigned vol=N*N*N;
        long long unsigned aa=A[0]+A[1]+x+x;
        if(vol==aa)
        flag=true;
        if(!flag)
        {
            cout<<"Impossible\n";
            continue;
        }
        flag=false;
        if(x*x==A[0]*A[1])
        flag=true;
        if(!flag)
        {
            cout<<"Impossible\n";
            continue;
        }

        cout<<"Possible\n";
    }
    return 0;
}
