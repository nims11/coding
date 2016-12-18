#include<iostream>
#include<string>
#include<sstream>
using namespace std;
char toLower(char x)
{
    if(x>='A' && x<='Z')
    return x-'A'+'a';
    return x;
}
int main()
{
    while(1)
    {
        int t;
        string str;
        getline(cin,str);
        if(str[0]=='*')
        {
            return 0;
        }
        stringstream ss(str);
        char x=-1;
        int len=0;
        bool flag=true;
        while(ss>>str)
        {
            len++;
            if(x==-1)
            x=toLower(str[0]);
            else
            if(toLower(str[0])!=x)
            {
                flag=false;
                break;
            }
        }
        if(len!=0)
        {
        if(flag)
        cout<<'Y'<<endl;
        else
        cout<<'N'<<endl;
        }
    }

}
