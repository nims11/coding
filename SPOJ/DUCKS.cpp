#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore(1);
    while(t--)
    {
        bool name[300];
        for(int i=0;i<300;i++)
        name[i]=false;
        name['D']=name['u']=name['c']=name['k']=name['y']=true;
        string str;
        getline(cin,str);
        if(str=="")
        {
            t++;
            continue;
        }
        int count=0;
        for(int i=0;i<str.length() && count<5;i++)
        {
            if(name[str[i]])
            {
                count++;
                name[str[i]]=false;
            }else if(str[i]!='.' && str[i]!='D' && str[i]!='u' && str[i]!='c' && str[i]!='k' && str[i]!='y' )
            {
                break;
            }
        }
        if(count==5)
        {
            printf("DUCKY IS HERE!\n");
        }else
        printf("NO DUCKY!\n");
    }
    return 0;
}
