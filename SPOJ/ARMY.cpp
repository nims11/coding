/*
The team with the stongest one wins.
*/
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int NG,NM;
        cin>>NG>>NM;
        int god=0,mech=0;
        for(int i=0;i<NG;i++)
        {
            int tmp;
            cin>>tmp;
            if(tmp>god)
            god=tmp;
        }
        for(int i=0;i<NM;i++)
        {
            int tmp;
            cin>>tmp;
            if(tmp>mech)
            mech=tmp;
        }
        if(god>=mech)
        cout<<"Godzilla\n";
        else
        cout<<"MechaGodzilla\n";
    }

    return 0;
}
