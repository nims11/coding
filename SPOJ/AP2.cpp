#include<iostream>

int main()
{
    int t;
    std::cin>>t;
    while(t--)
    {
        long long t2,tn_2,sum,n,d;
        std::cin>>t2>>tn_2>>sum;
        n=(2*sum)/(t2+tn_2);
        d=(tn_2-t2)/(n-5);
        std::cout<<n<<"\n";
        long long a=t2-2*d;
        for(long long i=0;i<n;i++)
        {
            std::cout<<a<<" ";
            a+=d;
        }
        std::cout<<"\n";
    }
    return 0;
}
