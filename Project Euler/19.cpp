#include<iostream>
using namespace std;
int days_in[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int year=1900,curr_mon=1,curr_day=0,count=0;
    while(year<2001)
    {
        for(int i=1;i<=12;i++)
        {
            if(curr_day==6 && year>1900)
            {
                count++;
            }
//            cout<<i<<" "<<year<<" "<<curr_day<<endl;
            curr_day=curr_day+days_in[i];
            if(year%4==0 && (year%100!=0 || year%400==0))
            if(i==2)
            curr_day++;
            curr_day%=7;
        }

        year++;
    }
    cout<<count<<endl;
    return 0;
}
