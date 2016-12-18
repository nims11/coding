#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char ch[50];
        cin>>ch;
        int n=strlen(ch);
        bool flag=true;
        for(int i=0;i<n;i++)
        if(ch[i]=='D')
        {
            flag=false;
            break;
        }
        if(flag)
        cout<<"Possible\n";
        else
        cout<<"You shall not pass!\n";
    }
    return 0;
}
