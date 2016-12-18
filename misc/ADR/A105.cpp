#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        for(int i=0;i<str.length();i++)
        cout<<str.substr(0,i+1)<<endl;
        for(int i=1;i<str.length();i++)
        cout<<str.substr(i)<<endl;
        cout<<endl;
    }
}
