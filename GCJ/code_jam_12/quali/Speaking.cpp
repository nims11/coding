#include<iostream>
#include<string>
using namespace std;
char mapping[26];
void getMappings()
{
    for(int i=0;i<26;i++)
    mapping[i]=0;
    string strG[3]={"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    string strE[3]={"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};
    mapping['z'-'a']='q';
    mapping['q'-'a']='z';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<strG[i].length();j++)
        {
            if(strG[i][j]>='a' && strG[i][j]<='z')
            mapping[strG[i][j]-'a']=strE[i][j];
        }
    }
    for(int i=0;i<26;i++)
    {
        if(mapping[i]==0)
        cout<<char('a'+i)<<endl;
    }
}
int main()
{
    getMappings();
    bool x[26];
    for(int i=0;i<26;i++)
    {
        //cout<<char('a'+i)<<" "<<mapping[i]<<endl;
    }
    int t;
    cin>>t;
    cin.ignore(1);
    for(int z=0;z<t;z++)
    {
        string str;
        string str2;
        getline(cin,str);
        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                str2.push_back(mapping[str[i]-'a']);
            }else
            str2.push_back(str[i]);
        }
        cout<<"Case #"<<z+1<<": "<<str2<<endl;
    }
    return 0;
}
