#include <iostream>
using namespace std;
void merge(long long arr[],long long arr2[],long long arr3[],long long beg,long long mid,long long end)
{
    long long i=0,j=0;
    long long count=beg;
    while(!(i==mid+1-beg && j==end-mid))
    {
        if(i==mid+1-beg)
        {
            arr[count++]=arr3[j++];
            continue;
        }
        if(j==end-mid)
        {
            arr[count++]=arr2[i++];
            continue;
        }

        if(arr2[i]>arr3[j])
        arr[count++]=arr3[j++];
        else
        arr[count++]=arr2[i++];

    }
}
void mergeSort(long long arr[],long long beg, long long end)
{
    long long n1=end-beg+1;
if(n1!=1)
{
    long long mid=(beg+end)/2;

    long long *arr2=new long long[mid-beg+1];
    long long *arr3=new long long[end-mid];
    for(long long i=0;i<mid-beg+1;i++)
        arr2[i]=arr[beg+i];

    for(long long i=0;i<end-mid;i++)
        arr3[i]=arr[mid+1+i];

        mergeSort(arr2,0,mid-beg);
        mergeSort(arr3,0,end-mid-1);

        merge(arr,arr2,arr3,beg,mid,end);

        delete [] arr2;
        delete [] arr3;
}
}

