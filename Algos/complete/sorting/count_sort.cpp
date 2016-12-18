#include<iostream>

void count_sort(int *a,int *b,int len,int k)
{
    int *c=new int[k+1];

    for(int i=0;i<=k;i++)
    c[i]=0;

    for(int i=0;i<len;i++)
    c[a[i]]++;
    for(int i=1;i<=k;i++)
    c[i]+=c[i-1];

    for(int i=len-1;i>=0;i--)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
}
int main()
{
    int a[8],b[8];
    for(int i=0;i<8;i++)
    std::cin>>a[i];
    count_sort(a,b,8,5);
    for(int i=0;i<8;i++)
    std::cout<<b[i]<<" ";
}
