#include<iostream>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long res;char op;long long n;
        cin>>res;
        while(1)
        {
            cin>>op;
            if(op=='=')
            {
                cout<<res<<endl;
                break;
            }
            cin>>n;
            switch(op)
            {
                case '+':res+=n;break;
                case '-':res-=n;break;
                case '*':res*=n;break;
                case '/':res/=n;break;
            }
        }
    }
    return 0;
}
