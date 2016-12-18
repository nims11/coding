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
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
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
int main()
{
    int n;
    in_I(n);
    string strs[n];
    for(int i = 0;i<n;i++)
        cin>>strs[i];
    string str;
    cin>>str;
    int curr_ptr = 0;
    bool flag = true;
    string str2 = "<3";
    int cur_ptr2 = 0;
        while(cur_ptr2 < 2 && curr_ptr < str.length())
        {
            if(str2[cur_ptr2] != str[curr_ptr])
                curr_ptr++;
            else
                curr_ptr++, cur_ptr2++;
        }
        if(cur_ptr2 != 2)
        {
            flag  = false;
        }
    for(int i = 0;i<n;i++)
    {
        int cur_ptr2 = 0;
        while(cur_ptr2 < strs[i].length() && curr_ptr < str.length())
        {
            if(strs[i][cur_ptr2] != str[curr_ptr])
                curr_ptr++;
            else
                curr_ptr++, cur_ptr2++;
        }
        if(cur_ptr2 != strs[i].length())
        {
            flag  = false;
            break;
        }
        cur_ptr2 = 0;
        while(cur_ptr2 < 2 && curr_ptr < str.length())
        {
            if(str2[cur_ptr2] != str[curr_ptr])
                curr_ptr++;
            else
                curr_ptr++, cur_ptr2++;
        }
        if(cur_ptr2 != 2)
        {
            flag  = false;
            break;
        }
    }
    cout<<(flag?"yes":"no")<<endl;
}
