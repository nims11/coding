
#include<iostream>
#include<cstdlib>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int m,n,k;
        cin>>m>>n>>k;
        int count=m;
        int *a=new int[m+1];
        for(int j=1;j<=m;j++)
        a[j]=j+1;
        a[m]=1;
        int curr=1;
        while(count>k)
        {
            int index=1;
            while(index<n)
            {
                curr=a[curr];
                index++;
            }
            int tmp=a[curr];
            a[curr]=0;
            for(int j=1;j<=m;j++)
            if(a[j]==curr)
            {
                a[j]=tmp;
                break;
            }
            curr=tmp;
            count--;
        }
        a[0]=0;
        qsort (a, m+1, sizeof(int), compare);
        cout<<"Case #"<<i<<":";
        for(int j=1;j<=m;j++)
        if(a[j]!=0)cout<<" "<<a[j];
        cout<<endl;
        delete [] a;
    }
    return 0;
}
