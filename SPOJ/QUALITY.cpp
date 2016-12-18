#include<iostream>
using namespace std;
int main()
{
    int a[3],b[3];
    int k=0;
    while(cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2])
    {
        k++;
        int solved=0;
        long long pen=0;
        for(int i=0;i<3;i++)
        {
            if(a[i]){
                solved++;
                pen+=a[i]+20*60*(b[i]-1);
            }
        }
        cout<<"team "<<k<<": "<<solved<<", "<<pen<<endl;

    }
}
