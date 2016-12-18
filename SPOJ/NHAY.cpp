#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        string H,N;
        cin>>N>>H;
        size_t count=0;
        size_t curr=0;
        curr=H.find(N,curr+1);;
        while(curr<H.size() && curr!=string::npos)
        {
            cout<<curr<<endl;
            curr=H.find(N,curr+1);
            count++;
        }
        if(count==0)
        cout<<'\n';
    }
}
