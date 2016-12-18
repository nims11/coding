/*
    Nimesh Ghelani (nims11)
    Every number divisible by 5 must have a 5 or a 0 at its end.
    Every number divisible by 3 must have its sum of digits divisible by 3.
    Combine these two properties.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    in_T
    {
        string tmp;
        cin>>tmp;
        int count[20]={0},sum=0;
        for(int i=0;i<tmp.length();i++)
        {
            count[tmp[i]-'0']++;
            sum+=tmp[i]-'0';
        }
        if(count[5]==0 && count[0]==0)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        bool five=false;
        if(count[5] && !count[0]){five=true;count[5]--;}
        if(sum%3==1)
        {
            for(int i=1;i<10;i+=3)
            {
                if(count[i])
                {
                    count[i]--;
                    sum-=i;
                    break;
                }
            }
            if(sum%3==1)
            {
                for(int i=2;i<10 && sum%3;i+=3)
                {
                    for(int j=2;j<10;j+=3)
                    {
                        if(i==j)
                        {
                            if(count[i]>1)
                            {
                                count[i]-=2;sum-=2*i;break;
                            }
                        }else
                        {
                            if(count[i] && count[j])
                            {
                                count[i]--,count[j]--;sum-=i+j;break;
                            }
                        }
                    }
                }
            }
        }else if(sum%3==2)
        {
            for(int i=2;i<10;i+=3)
            {
                if(count[i])
                {
                    count[i]--;
                    sum-=i;
                    break;
                }
            }
            if(sum%3==2)
            {
                for(int i=1;i<10 && sum%3;i+=3)
                {
                    for(int j=1;j<10;j+=3)
                    {
                        if(i==j)
                        {
                            if(count[i]>1)
                            {
                                count[i]-=2;sum-=2*i;break;
                            }
                        }else
                        {
                            if(count[i] && count[j])
                            {
                                count[i]--,count[j]--;sum-=i+j;break;
                            }
                        }
                    }
                }
            }
        }
        if(sum%3!=0)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        vector<int> ans;
        if(five)ans.push_back(5);
        for(int i=0;i<10;i++)
        {
            while(count[i]--)
            ans.push_back(i);
        }
        if(ans[ans.size()-1]==0)cout<<0<<endl;
        else
        {
            for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
            cout<<endl;
        }
    }
}
