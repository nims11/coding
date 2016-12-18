#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        bool flag=false;
        string left="",right="";
        string mid;
        for(int i=0;i<n;i++)
        {
            cin>>str;

            //cout<<"*"<<str<<endl;
            if(str[0]>='a' && str[0]<='z')
            {mid=str;flag=true;}
            else
            {
            if(!flag)
            left+=str+" ";
            else
            right+=str+" ";
            }
        }
        if(flag)
        cout<<right<<mid<<" "<<left<<endl;
        else
        cout<<left<<endl;
    }
    return 0;
}
