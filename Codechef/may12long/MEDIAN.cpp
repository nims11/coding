#include<iostream>
using namespace std;
int getAns(long long a[],int count[],long long max,int end,int required)
{
    if(required<=0)
    return 1;
    int ans=0;
    for(int i=end;i>=2;i--)
    {
        for(int j=end-i+1;j>=1;j--)
        {
            if((i+1)/2 <= count[j+i-1]-count[j-1])
            {
                int oldreq=required;
                for(int k=j;k<=j+i-1;k++)
                {
                    if(a[k]!=max)
                    {
                        a[k]=max;
                        required--;
                    }
                }
                if(oldreq!=required)
                ans++;
                for(int k=1;k<=end;k++)
                {
                    count[k]=count[k-1];
                    if(a[k]==max)
                    count[k]++;
                }
                if(required>0)
                {
                    i=end+1;
                    break;
                }else
                return ans;

            }
        }
    }
    return 0;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a[31];
        int n;
        int count[31]={0};
        cin>>n;
        long long max=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>max)
            max=a[i];
        }
        for(int i=1;i<=n;i++)
        {
            count[i]=count[i-1];
            if(a[i]==max)
            count[i]++;
        }
        int required=n-count[n];
        int ans;
        ans=getAns(a,count,max,n,required);
        cout<<ans<<endl;
    }
    return 0;
}
