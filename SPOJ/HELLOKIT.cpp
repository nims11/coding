#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;int n;
    cin>>s;
    while(s!=".")
    {
        cin>>n;
        string s2="";
        for(int i=0;i<n;i++)
        s2+=s;
        int s_len=s.length();
        int s2_len=s_len*n;

        for(int i=0;i<s_len;i++)
        {
            for(int j=i;j<i+s2_len;j++)
            {
                cout<<s2[j%s2_len];
            }
            cout<<endl;
        }

        cin>>s;
    }
    return 0;
}
