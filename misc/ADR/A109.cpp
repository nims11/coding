#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore(1);
    string str;
    while(t--)
    {
        getline(cin,str);
        int start=0,end=0;
        while(start<str.length())
        {
            while(end<str.length() && str[end]>='A' && str[end]<='Z')end++;
            cout<<str[end-3];
            while(start!=end-3)cout<<str[start++];
            start=end;
            while(start<str.length() && !(str[start]>='A' && str[start]<='Z'))cout<<str[start++];
            end=start;
        }
        cout<<endl;
    }

}

