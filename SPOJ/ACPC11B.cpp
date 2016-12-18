#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore(1);
    while(t--)
    {
        long long n1,n2,min=1000004;
        vector<long long> a1;
        cin>>n1;
        for(int i=0;i<n1;i++)
        {
            cin>>n2;
            a1.push_back(n2);
        }
        sort(a1.begin(),a1.end());
        cin>>n2;
        while(n2--)
        {
            cin>>n1;
            long long diff;
            for(int i=0;i<a1.size() && min!=0;i++)
            {
                diff=abs(n1-a1[i]);
//                cout<<diff<<endl;
                if(diff<min)min=diff;
                if(n1<a1[i])
                break;
            }
        }
        cout<<min<<endl;

    }
    return 0;
}
