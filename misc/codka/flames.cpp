#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string FLAMES[6]={"FRIENDS","LOVE","ADORE","MARRIAGE","ENEMIES","SISTER"};
int getN(string str1,string str2,int len1,int len2)
{
    int ans=len1+len2;
    int i=0,j=0;
    transform(str1.begin(), str1.end(),str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(),str2.begin(), ::toupper);

    while(i<len1)
    {
        for(int k=j;k<len2;k++)
        {
            if(str1[i]==str2[k])
            {
                ans-=2;
                j=k+1;
                break;
            }
        }
        i++;
    }
    return ans;
}
int getAns(int size,int c)
{
    int *a=new int[size];
    for(int i=0;i<size;i++)
    a[i]=i+1;
    a[size-1]=0;
    int count=size,curr=0;
    while(count!=1)
    {
        for(int i=0;i<c-1;i++)
        curr=a[curr];
        for(int i=0;i<size;i++)
        if(a[i]==curr)
        {
            a[i]=a[curr];
            a[curr]=-1;
            curr=a[i];
        }
        count--;
    }
    delete [] a;
    return curr;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        int len1=str1.length(),len2=str2.length();
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        int n=getN(str1,str2,len1,len2);
        cout<<FLAMES[getAns(6,n)]<<endl;
    }

    return 0;
}
