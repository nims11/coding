/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
string str1, str2;
int curr1, curr2;
int pow_4[6];
void exhaust1(int &pos1)
{
    if(str1[pos1]!='p'){pos1++;return;}
    pos1++;
    for(int i=0;i<4;i++)
    {
        exhaust1(pos1);
    }
}
void exhaust2(int &pos2)
{
    if(str2[pos2]!='p'){pos2++;return;}
    pos2++;
    for(int i=0;i<4;i++)
    {
        exhaust2(pos2);
    }
}
int count_all1(int &pos1, int depth)
{
    if(str1[pos1] == 'f')
    {
        pos1++;
        return pow_4[5-depth];
    }else if(str1[pos1]=='e')
    {
        pos1++;
        return 0;
    }else
    {
        pos1++;
        int ans=0;
        for(int i=0;i<4;i++)
            ans += count_all1(pos1, depth+1);
        return ans;
    }
}
int count_all2(int &pos1, int depth)
{
    if(str2[pos1] == 'f')
    {
        pos1++;
        return pow_4[5-depth];
    }else if(str2[pos1]=='e')
    {
        pos1++;
        return 0;
    }else
    {
        pos1++;
        int ans=0;
        for(int i=0;i<4;i++)
            ans += count_all2(pos1, depth+1);
        return ans;
    }
}
int getans(int &pos1, int &pos2, int depth)
{
//    cout<<pos1<<" "<<pos2<<endl;
    if(str1[pos1] == 'f' || str2[pos2] == 'f')
    {
        exhaust1(pos1);
        exhaust2(pos2);
        return pow_4[5-depth];
    }
    if(str1[pos1] == 'e' && str2[pos2] == 'e')
    {
        pos1++, pos2++;
        return 0;
    }
    int ans = 0;
    if(str1[pos1] == 'e')
        pos1++,ans =count_all2(pos2, depth);
    else if(str2[pos2] == 'e')
        pos2++,ans = count_all1(pos1, depth);
    else
    {
        pos1++, pos2++;
        for(int i=0;i<4;i++)
        {
            ans += getans(pos1, pos2, depth+1);
        }
    }
    return ans;
}
int main()
{
    pow_4[0] = 1;
    for(int i=1;i<6;i++)
        pow_4[i] = pow_4[i-1]*4;
    in_T
    {
        cin>>str1>>str2;
        curr1=curr2 = 0;
        int pos1=0,pos2=0;
        cout<<getans(pos1, pos2, 0)<<" black pixels."<<endl;
    }
}
