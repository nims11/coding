#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int getIndex(char ch)
{
    ch=toupper(ch);
    switch(ch)
    {
        case 'H':return 0;
        case 'A':return 1;
        case 'C':return 2;
        case 'K':return 3;
        case 'E':return 4;
        case 'R':return 5;
        case 'U':return 6;
        case 'P':return 7;
    }
    return 8;
}
int getMin(int hackercup[])
{
    hackercup[2]/=2;
    int min=hackercup[0];
    for(int i=1;i<8;i++)
    if(hackercup[i]<min)
    min=hackercup[i];
    return min;
}
int main()
{
    int t;
    cin>>t;
    cin.ignore(1);
    for(int z=1;z<=t;z++)
    {
        int hackercup[9];
        //h,a,c,k,e,r,u,p
        for(int i=0;i<9;i++)
        hackercup[i]=0;
        string str;
        getline(cin,str);
        int len=str.length();
        for(int i=0;i<len;i++)
        {
            hackercup[getIndex(str[i])]++;
        }
        cout<<"Case #"<<z<<": "<<getMin(hackercup)<<endl;

    }
    return 0;
}
