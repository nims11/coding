#include<iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j;
        for(j=i-1;j>=0 && a[j]>key;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
}
int main()
{
    int a[12]={3,2,54,3,24,32,1,21,312,35,43,6};
    insertion_sort(a,12);
    for(int i=0;i<12;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
