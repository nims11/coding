#include<iostream>
template <typename T> int partition(T *a, int p, int r)
{
    T x=a[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            T tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
    i++;
    T tmp=a[i];
    a[i]=a[r];
    a[r]=tmp;
    return i;

}
template <typename T> void quick_sort(T *a,int p,int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}
int main()
{
    int a[5];
    for(int i=0;i<5;i++)
    std::cin>>a[i];

    quick_sort(a,0,4);

    for(int i=0;i<5;i++)
    std::cout<<a[i];
}
