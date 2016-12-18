/*
 * the objective is to find the minimum number of pizzas to serve people who want either 1/2, 1/4 or 3/4 of the pizza. The catch here is that fractions
 * cannot be carried over to the next pizza.
 * first consider the 3/4th slices and compensate the remaining 1/4th slice according to the demand.
 * then consider the 1/2 slices. the one 1/2 slice remains, compensate with 1/4th slice if possible.
 * at last consider the remaining 1/4th slices.
 */
#include<iostream>
#include<cstdio>
using namespace std;
int count[3]={};
int pizz=1;
// 0-1/4 1-1/2 2-3/4

int main()
{
    int n;
    int ch1,ch2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d/%d",&ch1,&ch2);
        if(ch1==1)
        {
            if(ch2==4)
            count[0]++;
            else count[1]++;

        }else
        count[2]++;
    }
    pizz+=count[2];
    if(count[2]>count[0])
    count[0]=0;
    else
    count[0]-=count[2];
    pizz+=count[1]/2;
    count[1]-=2*(count[1]/2);
    if(count[1])
    {
        pizz+=count[1];
        count[0]-=2;
    }
    if(count[0]>0)
    {pizz+=count[0]/4;
    count[0]%=4;}
    if(count[0]>0)
    pizz++;
    cout<<pizz<<endl;
    return 0;
}
