#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int k=1;
    while(cin>>str)
    {
        bool flip=false;
        int count=0;
        for(int i=0;i<str.length();i++)
        {
            if((str[i]=='1')==!flip)
            {
                flip=!flip;
                count++;
            }
        }
        cout<<"Game #"<<k<<": "<<count<<endl;
        k++;
    }
    return 0;
}
