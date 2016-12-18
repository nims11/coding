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
        int i=0;
        while(i<str.length())
        {
            int tmp;
            if(str[i]==' '){i++;continue;}

            if(str[i]>='0' && str[i]<='9'){
                tmp=str[i]-'0';
                i++;
                if(i<str.length() && (str[i]>='0' && str[i]<='9')){tmp=tmp*10+str[i]-'0';cout<<char('A'-1+tmp);i++;continue;}
                else{cout<<char('A'-1+tmp);continue;}
            }

            if(str[i]=='_'){cout<<" ";i++;continue;}
            if(str[i]=='#')
            {
                tmp=0;
                i++;
                while(i<str.length() && (str[i]>='0' && str[i]<='9'))
                {
                    cout<<str[i++];
                }
                continue;
            }

            cout<<str[i++];
        }
        cout<<endl;
    }

}
