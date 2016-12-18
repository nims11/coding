
/*
    Nimesh Ghelani (nims11)
    Straightforward ad-hoc problem
    iterate through the score and suitably updating the current state.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<sstream>
#define in_T int t;for(scanf("%d\n",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
	in_T
	{
		string tmps;
		getline(cin,tmps);
		stringstream ss(tmps);
		int scores[100],count=0;
		while(ss>>scores[count])count++;
		int frame=1,curr=0,ans=0;
		while(1)
		{
			if(frame==10)
			{
				while(curr<count)
				{
					ans+=scores[curr];curr++;
				}
				break;
			}
			ans+=scores[curr];
			if(scores[curr]==10)
			{
				ans+=scores[curr+1]+scores[curr+2];
			}else if(scores[curr]+scores[curr+1]==10)
			{
				ans+=scores[curr+1]+scores[curr+2];
				curr++;
			}
			else ans+=scores[++curr];
			curr++;
			frame++;
		}
		cout<<ans<<endl;
	}
}
