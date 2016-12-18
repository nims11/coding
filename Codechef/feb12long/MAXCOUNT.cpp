#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int buff[100001],n;
        cin>>n;
        for(int i=0;i<100001;i++)
        {
            buff[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            buff[x]++;
        }
        int num,count=0;
        for(int i=100000;i>=0;i--)
        {
            if(buff[i]>=count)
            {
                count=buff[i];
                num=i;
            }
        }
        cout<<num<<" "<<count<<endl;
    }
    return 0;
}
