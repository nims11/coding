#include<iostream>
#include<cmath>
#include<cstdio>
#define PI 3.14159
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        printf("%.4f\n",8*(2-sqrt(2))*n*n*n);
    }
    return 0;
}
