#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int n,p;
        int a[10][10];
        cin>>n>>p;
        for(int i=0;i<n;i++)
        for(int j=0;j<p;j++)
        cin>>a[i][j];
        bool x,y,z;
        x=true;
        for(int i=0;i<p;i++)
        {
            bool tmp=false;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]!=0)
                {
                    tmp=true;
                    break;
                }
            }
            if(!tmp)
            {
                x=false;
                break;
            }
        }
        int max=0,min=100;
        for(int i=0;i<n;i++)
        {
            int k=0;
            for(int j=0;j<p;j++)
            k+=a[i][j];
            if(k<min)
            min=k;
            if(k>max)
            max=k;
        }
        if(max<p)
        z=true;
        else
        z=false;
        if(min==1)
        y=true;
        else
        y=false;

        int ans=0;
        ans+=int(z)*1;
        ans+=int(y)*2;
        ans+=int(x)*4;
        cout<<"Case "<<q<<": "<<ans<<endl;
    }
}
