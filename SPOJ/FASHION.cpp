#include <iostream>
using namespace std;
void merge(int arr[],int arr2[],int arr3[],int beg,int mid,int end)
{
    int i=0,j=0;
    int count=beg;
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
void mergeSort(int arr[],int beg, int end)
{
    int n1=end-beg+1;
if(n1!=1)
{
    int mid=(beg+end)/2;

    int *arr2=new int[mid-beg+1];
    int *arr3=new int[end-mid];
    for(int i=0;i<mid-beg+1;i++)
        arr2[i]=arr[beg+i];

    for(int i=0;i<end-mid;i++)
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
  int t;
  cin>>t;
  while(t--)
  {
    int n,sum=0;
    cin>>n;
    int *h1=new int[n];
    int *h2=new int[n];
    
    for(int i=0;i<n;i++)
    cin>>h1[i];
    for(int i=0;i<n;i++)
    cin>>h2[i];
    
    mergeSort(h1,0,n-1);
    mergeSort(h2,0,n-1);
    for(int i=0;i<n;i++)
      sum+=(h1[i]*h2[i]);
    cout<<sum<<endl;
    delete [] h1;
    delete [] h2;
  }
  return 0;
}
