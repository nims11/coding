#include <iostream>
#include <cstring>
using namespace std;
int triangle[100][100], buffer[100][100];
int getBestPath(int r,int c)
{
    if(buffer[r][c]!=-1)
    return buffer[r][c];

    int path1=getBestPath(r+1,c);
    int path2=getBestPath(r+1,c+1);

    if(path1>path2)
    {
        buffer[r][c]=triangle[r][c]+path1;
        return buffer[r][c];
    }else
    {
        buffer[r][c]=triangle[r][c]+path2;
        return buffer[r][c];
    }
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int dimension;
        cin>>dimension;

        for(int i=0;i<dimension;i++)
        for(int j=0;j<=i;j++)
        buffer[i][j]=-1;

        for(int i=0;i<dimension;i++)
        for(int j=0;j<=i;j++)
        cin>>triangle[i][j];

        for(int i=0;i<dimension;i++)
        buffer[dimension-1][i]=triangle[dimension-1][i];

        cout<<getBestPath(0,0)<<endl;
    }
    return 0;
}
