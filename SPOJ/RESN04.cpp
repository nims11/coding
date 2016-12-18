#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,moves=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int si;
            cin>>si;
            moves+=si/i;
        }
        if(moves%2==0)
        cout<<"BOB\n";
        else
        cout<<"ALICE\n";
    }
    return 0;
}
