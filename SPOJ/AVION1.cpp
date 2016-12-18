/*
Find all occurences of a substring
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int ans=0;
    for(int i=0;i<5;i++)
    {
        string str;
        cin>>str;
        if(str.find("FBI")!=string::npos)
        {
            cout<<i+1<<" ";
            ans++;
        }
    }
    if(ans==0)
    cout<<"HE GOT AWAY!\n";
    cout<<endl;
    return 0;
}
