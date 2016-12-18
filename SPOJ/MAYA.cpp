#include<iostream>
#include<map>
#include<string>
using namespace std;
long long pow(int x,int y)
{
    long long ans=1;
    for(int i=0;i<y;i++)
    ans*=x;
    return ans;
}
int main()
{
    int n;
    map <string,int> maya;
    maya["S"]=0;
    maya["."]=1;maya[".."]=2;maya["..."]=3;maya["...."]=4;
    maya["-"]=5;maya[". -"]=6;maya[".. -"]=7;maya["... -"]=8;maya[".... -"]=9;
    maya["- -"]=10;maya[". - -"]=11;maya[".. - -"]=12;maya["... - -"]=13;maya[".... - -"]=14;
    maya["- - -"]=15;maya[". - - -"]=16;maya[".. - - -"]=17;maya["... - - -"]=18;maya[".... - - -"]=19;

    while(cin>>n)
    {
        if(n==0)
        return 0;
        cin.ignore(1);
        string str;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            getline(cin,str);
            long long x=maya[str];
            if(n-i-1>=2)
            x*=360*pow(20,(n-i-1-2));
            else
            {
                if(n-i-1==1)
                x*=20;
            }
            ans+=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
