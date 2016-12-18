#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==1)
        cout<<"*"<<endl;
        else{

        for(int i=0;i<n/2;i++)
        {
            cout<<" ";
        }
        cout<<"*"<<endl;
        for(int i=1;i<n/2;i++)
        {
            for(int j=0;j<n/2-i;j++)
            cout<<" ";
            cout<<"*";
            for(int j=1;j<i;j++)
            cout<<" ";
            cout<<"*";
            for(int j=1;j<i;j++)
            cout<<" ";
            cout<<"*";
            cout<<endl;
        }
        for(int i=0;i<n;i++)
        cout<<"*";
        cout<<endl;
        for(int i=n/2-1;i>=1;i--)
        {
            for(int j=0;j<n/2-i;j++)
            cout<<" ";
            cout<<"*";
            for(int j=1;j<i;j++)
            cout<<" ";
            cout<<"*";
            for(int j=1;j<i;j++)
            cout<<" ";
            cout<<"*";
            cout<<endl;
        }

        for(int i=0;i<n/2;i++)
        {
            cout<<" ";
        }
        cout<<"*"<<endl;


    }}
    return 0;
}
