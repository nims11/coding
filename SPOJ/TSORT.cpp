#include <iostream>
#include <cstring>
using namespace std;
void getInput(long *num)
{
    cin.ignore(1);
    long count=0;
    long t=0;
    while(!cin.eof())
    {
        char stream[65536];
        cin.read(stream,65536);
        long size=strlen(stream);
        for(long i=0;i<size;i++)
        {
            if(stream[i]=='\n')
            {
                //cout<<i<<" "<<t<<endl;
                num[count++]=t;
                t=0;
                continue;
            }else
            t=t*10+stream[i]-'0';
        }
    }
}
void merge(long arr[],long arr2[],long arr3[],long beg,long mid,long end)
{
    long i=0,j=0;
    long count=beg;
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
void mergeSort(long arr[],long beg, long end)
{
    long n1=end-beg+1;
if(n1!=1)
{
    long mid=(beg+end)/2;

    long *arr2=new long[mid-beg+1];
    long *arr3=new long[end-mid];
    for(long i=0;i<mid-beg+1;i++)
        arr2[i]=arr[beg+i];

    for(long i=0;i<end-mid;i++)
        arr3[i]=arr[mid+1+i];

        mergeSort(arr2,0,mid-beg);
        mergeSort(arr3,0,end-mid-1);

        merge(arr,arr2,arr3,beg,mid,end);

        delete [] arr2;
        delete [] arr3;
}
}
int main()
{
    long t;
    cin>>t;
    long *num=new long[t];
    getInput(num);
    mergeSort(num,0,t-1);

    for(long i=0;i<t;i++)
    cout<<num[i]<<endl;
    delete [] num;
    return 0;
}
