#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int p,n;
    cin>>p>>n;
    char ch;
    vector<int>pos;
    for(int i=1;i<=p;i++)
    {
        cin>>ch;
        if(ch=='+')
        {
            pos.push_back(i);
        }else
        pos.push_back(-i);
    }
    int count=1;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(pos[curr]>0 && pos[curr]+tmp<=p){curr+=tmp;}
        else if(pos[curr]<0 && -pos[curr]-tmp>=1){curr-=tmp;}
        if(curr==0)count++;
    }
    cout<<count<<endl;
}
