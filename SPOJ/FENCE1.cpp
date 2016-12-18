#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int l;double pi=3.14159265;
    while(cin>>l)
    {
        if(l==0)
        return 0;

        printf("%.2f\n",l*l/pi/2);
    }
    return 0;
}


