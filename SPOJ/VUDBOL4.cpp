#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
        break;
        string str;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            string str2;
            for(int i=0;i<str.length();i++)
            {
                str2.push_back(str[i]);str2.push_back(str[i]);
            }
            cout<<str2<<"\n"<<str2;
            cout<<"\n";
        }
    }
    return 0;
}
