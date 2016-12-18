#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
    long breaks[33];
    for(int i=0;i<33;i++)
    breaks[i]=pow(2,i);

    long n;
    cin>>n;
    while(cin>>n)
    {
        cout<<breaks[(long)floor(log2(n))]<<endl;
    }
    return 0;
}
