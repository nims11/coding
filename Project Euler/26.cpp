#include<iostream>
#include<vector>
using namespace std;
int insert(int divi,vector <int> &dividends)
{
    int size=dividends.size();
    for(int i=0;i<size;i++)
    {
        if(divi==dividends[i])
        return size-i;
    }
    dividends.push_back(divi);
    return -1;
}
int main()
{
    int max=0;
    int maxd;
    for(int i=2;i<1000;i++)
    {
        int divi=10;
        vector<int> dividends;
        while(divi!=0)
        {
            int x=insert(divi,dividends);
            if(x!=-1)
            {
                cout<<x<<" "<<i<<endl;
                if(max<=x)
                {
                    max=x;
                    maxd=i;
                }
                break;
            }
            divi%=i;
            divi*=10;
        }
    }
    cout<<maxd<<endl;
    return 0;
}
