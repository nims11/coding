#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string J,S;
        map <int,int> jewel;
        cin>>J>>S;
        for(int i=0;i<J.length();i++)
        if(jewel.find(J[i])!=jewel.end())
        jewel[J[i]]++;
        else
        jewel[J[i]]=1;

        int count=0;
        for(int i=0;i<S.length();i++)
        {
            if(jewel.find(S[i])!=jewel.end())
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
