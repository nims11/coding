#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int a,d;
    while(cin>>a>>d)
    {
        if(a==0 && d==0)
        return 0;

        vector <int> attack,defense;
        for(int i=0;i<a;i++)
        {
            int x;
            cin>>x;
            attack.push_back(x);
        }
        for(int i=0;i<d;i++)
        {
            int x;
            cin>>x;
            defense.push_back(x);
        }
        sort(attack.begin(),attack.end());
        sort(defense.begin(),defense.end());

        char ans='N';
        if(attack[0]<defense[1])
        ans='Y';
        cout<<ans<<endl;

    }
    return 0;
}
