#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<long long unsigned> RB,RT,LB,LT;
    RB.push_back(1);
    LB.push_back(1);
    RT.push_back(1);
    LT.push_back(1);
    int i=1;
    int ddd=500;
    long long unsigned result=0;
    while(i<=ddd)
    {
        RB.push_back(RT[i-1]+2*i);
        LB.push_back(RT[i-1]+4*i);
        LT.push_back(RT[i-1]+6*i);
        RT.push_back(RT[i-1]+8*i);
        result+=RB[i]+LB[i]+LT[i]+RT[i];
        i++;
    }
    cout<<result+1<<endl;


    return 0;
}
