#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int k,n;
    string str;
    cin>>k>>n;
    vector<string> A;
    for(int i=0;i<k;i++)
    {
        cin>>str;
        A.push_back(str);
    }
    while(n--)
    {
        cin>>str;
        if(str.length()>=47)
        cout<<"Good\n";
        else
        {
            bool flag=false;
            for(int i=0;i<k;i++)
            {
                if(str.find(A[i])!=string::npos)
                {
                    flag=true;
                    cout<<"Good\n";
                    break;
                }
            }
            if(!flag)
            cout<<"Bad\n";
        }
    }
}
