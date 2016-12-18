#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        int *ar1=new int[n+1];
        int *ar2=new int[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>ar1[i];
            ar2[ar1[i]]=i;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(ar1[i]!=ar2[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        cout<<"ambiguous"<<endl;
        else
        cout<<"not ambiguous"<<endl;
        delete [] ar1;
        delete [] ar2;
        cin>>n;
    }
    return 0;
}
