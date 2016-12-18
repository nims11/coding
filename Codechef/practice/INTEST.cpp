#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long n,k,t=0,count=0;
    cin>>n>>k;
    int size=65536;
    char stream[65536];
    cin.ignore(1);
    while(!cin.eof())
    {
        cin.read(stream,65536);
        int size=strlen(stream);
        for(int i=0;i<size;i++)
        {
            if(stream[i]=='\n')
            {
                if(t%k==0)
                count++;
                t=0;
                continue;
            }else
            t=t*10+stream[i]-'0';
        }
    }
    cout<<count;
    return 0;
}
