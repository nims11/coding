#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int k=1;
    while(k<=t)
    {
        cout<<"Scenario #"<<k<<": ";
        int d,v;
        cin>>d>>v;
        double ans=(9.806*d)/v/v;
        if(ans>1 || ans<-1)
        cout<<-1<<endl;
        else
        {
            ans=0.5*asin(ans);
            ans=ans*180/(2*acos(0.0));
            printf("%.2lf\n",ans);
        }
        k++;
    }
    return 0;
}
