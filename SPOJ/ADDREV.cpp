#include <iostream>

using namespace std;
void reverse(int &num)
{
    int n=num;
    num=0;
    while(n>0)
    {
        num=num*10+n%10;
        n/=10;
    }
}
int main()
{

    int n;
cin>>n;
    while(n--)
    {
        int num1,num2,num3;cin>>num1>>num2;
        reverse(num1);reverse(num2);
        num3=num1+num2;
        reverse(num3);
        cout<<num3<<endl;
    }
    return 0;
}
