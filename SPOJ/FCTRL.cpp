#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        int count=0;
        float term=num/5;
        int n2=2;
        while(floor(term)>0)
        {
            count+=floor(term);
            term/=5;
        }
        cout<<count<<endl;
    }
    return 0;
}
