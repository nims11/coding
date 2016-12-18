/*
 * Modify the merge sort algo to get the number of inversions.
*/
#include<iostream>
#include<cstdio>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_L(a) scanf("%lld",&a)
long long ans;
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
        {
            ans+=mid+1-beg-i;
            arr[count++]=arr3[j++];
        }
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

}
}

int main()
{
    int arr[200002];
    in_T
    {
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
        in_I(arr[i]);
        ans=0;
        mergeSort(arr,0,n-1);
        printf("%lld\n",ans);
    }
}
