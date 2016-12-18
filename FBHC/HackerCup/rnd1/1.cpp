#include<iostream>
#include<cmath>
using namespace std;
const int size=50;
long grid[size][size];
void genGrid(int n)
{
    for(int i=0;i<n;i++)
    grid[0][i]=grid[i][0]=1;
    for(int i=1;i<n;i++)
    {
        grid[i][i]=2*grid[i-1][i];
        for(int j=i+1;j<n;j++)
        {
            grid[i][j]=grid[i][j-1]+grid[i-1][j];
            grid[j][i]=grid[i][j];
        }
    }
}
int searchGrid(long n)
{
    if(n==1)
    return 1;
    for(int j=1;j<=size;j++)
    {
        for(int i=1;i<=j;i++)
        {
            if(grid[i][j]==n)
            return i+j;
        }
    }
    for(long x=size+1;x<=n;x++)
    {
        //cout<<x<<endl;
        long a=2;
        long b=x+1;
        long j=1;
        long tmp=x;
        while(tmp<=n)
        {
            if(tmp==n)
            return j+x-1;
            tmp=(tmp*b)/a;
            b++,a++;
            j++;
            if(j>x-1)
            break;
        }
    }

    return -1;
}
int main()
{
    genGrid(size);
//    for(int i=0;i<=13;i++)
//    {
//        for(int j=0;j<=13;j++)
//        cout<<grid[i][j]<<"\t";
//        cout<<endl;
//    }
//    cout<<"***"<<grid[13][13]<<endl;
    int r;
    cin>>r;
    for(int z=1;z<=r;z++)
    {
        long s;
        cin>>s;
        int min_d=-1;
        int limit=sqrt(s);
        for(int i=1;i<=limit;i++)
        {
            if(s%i==0)
            {
                int a=searchGrid(i);
                int b=searchGrid(s/i);
                int d=a+b;
                if( (min_d>d || min_d==-1) && a!=-1 && b!=-1)
                min_d=d;
            }
        }
        cout<<"Case #"<<z<<": "<<min_d<<endl;
    }
    return 0;
}
