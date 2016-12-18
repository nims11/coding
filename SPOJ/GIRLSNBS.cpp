#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int b,g;
    cin>>b>>g;
    while(b!=-1)
    {
        cout<<ceil(float(max(b,g))/(min(b,g)+1))<<endl;
        cin>>b>>g;
    }
    return 0;
}
