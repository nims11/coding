#include<iostream>
#include<sstream>
#include<string>
#include<set>
using namespace std;
string toStr(long n)
{
    stringstream ss("");
    ss<<n;
    string str;
    ss>>str;
    return str;
}
long toInt(string str)
{
    stringstream ss("");
    ss<<str;
    long n;
    ss>>n;
    return n;
}
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        long count=0;
        long a,b;
        cin>>a>>b;
        for(long curr=a;curr<=b;curr++)
        {
            string str=toStr(curr);
            int len=str.length();
            //cout<<"*"<<str<<endl;
            set<long> nums;
            for(int i=1;i<len;i++)
            {
                int x=0;
                for(int j=i;;)
                {
                    //cout<<str[j];
                    x=x*10+str[j]-'0';
                    j=(j+1)%len;
                    if(j==i)
                    break;
                }
                //cout<<endl;
                //cout<<x<<endl;
                if(x>curr && x<=b)
                nums.insert(x);
            }
            count+=nums.size();
        }
        cout<<"Case #"<<z<<": "<<count<<endl;
    }

    return 0;
}
