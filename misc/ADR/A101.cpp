#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str,patt;
        cin>>str;
        int n=str.length();
        n-=n%2?1:0;
        while(n>0)
        {
            if(str.substr(0,n/2)==str.substr(n/2,n/2))
            {
                patt=str.substr(0,n/2);break;
            }
            n-=2;
        }
        int count=0;
        int curr=str.length()-n;
        while(count!=8)
        {cout<<patt[curr];curr=(curr+1)%patt.length();count++;}
        cout<<"...\n";
    }
}
