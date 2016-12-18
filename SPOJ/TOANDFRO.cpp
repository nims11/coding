#include <iostream>
using namespace std;
int main()
{
    int n;
    char str[202],tmp;
    cin>>n;
    while(n!=0)
    {
        int i=0;
        cin.ignore(1);
        while(1)
        {
            tmp=getchar();
            if(tmp<'a')
            break;
            int row=i/n;
            if(row%2==0)
            str[i]=tmp;
            else
            str[row*n+(n-(i%n)-1)]=tmp;
            i++;
        }
        int ul=i/n;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<ul;k++)
            cout<<str[k*n+j];
        }
        cout<<endl;
        cin>>n;
    }
    return 0;
}
