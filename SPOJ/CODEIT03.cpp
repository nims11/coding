#include<iostream>
#include<map>
#include<utility>
#include<string>
using namespace std;
void isLeap(map <int,bool> &isleap)
{
    for(int i=2012;i<=3000;i++)
    if(i%4==0 && (i%100!=0 || (i%400==0)))
    isleap[i]=true;
    else
    isleap[i]=false;
}
int main()
{
    map<int, string> Days;
    Days[0]="Monday";
    Days[1]="Tuesday";
    Days[2]="Wednesday";
    Days[3]="Thursday";
    Days[4]="Friday";
    Days[5]="Saturday";
    Days[6]="Sunday";

    map<int,int> year_day;
    year_day[2012]=6;
map<int,bool> isleap;
map<int,int> month_days;
month_days[0]=31;
month_days[1]=28;
month_days[2]=31;
month_days[3]=30;
month_days[4]=31;
month_days[5]=30;
month_days[6]=31;
month_days[7]=31;
month_days[8]=30;
month_days[9]=31;
month_days[10]=30;
month_days[11]=31;


    isLeap(isleap);
    for(int i=2013;i<=3000;i++)
    {
        if(isleap[i-1])
        year_day[i]=(year_day[i-1]+366)%7;
        else
        year_day[i]=(year_day[i-1]+365)%7;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int d,m,y;
        cin>>d>>m>>y;
        int ans=year_day[y];
        if(isleap[y])
        month_days[1]=29;
        else
        month_days[1]=28;
        ans=(ans+d-1)%7;
        for(int i=0;i<m-1;i++)
        ans=(ans+month_days[i])%7;

        cout<<Days[ans]<<endl;
    }
    return 0;
}
