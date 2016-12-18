#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore(1);
    while(t--)
    {
        string str;
        getline(cin,str);
        stringstream ss(str);
        int max=0;
        int curr=-1;
        int curr_len=-1;
        while(ss>>str){
//            cout<<str<<" "<<str.length()<<" "<<curr<<endl;

            if(str.length()==curr_len)
            curr++;
            else
            {
                if(curr>max)max=curr;
                curr_len=str.length();
                curr=1;
            }
        }
        if(curr>max)
        max=curr;
        if(max==0)
        {
            t++;
            continue;
        }
        cout<<max<<endl;
    }
    return 0;
}
