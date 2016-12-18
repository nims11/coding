
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define in_T int t;for(scanf("%d",&t);t--;)
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
int n; char str[51000];
bool any_4(int *arr)
{
	bool flag=false;
	for(int i=0;i<n;i++)
		if(arr[i]==4)
		{
			flag=true;
			arr[i]--;
		}
	return flag;
}
bool if_no_more_2(int *arr,int curr)
{
	for(int i=0;i<curr;i++)
		if(arr[i]>2)return false;
	for(int i=curr+1;i<n;i++)
		if(arr[i]>2)return false;
	return true;
}
bool more_than_2(int *arr,int curr)
{
	for(int i=0;i<curr;i++)
		if(arr[curr]-arr[i]<2)
			return false;
	for(int i=curr+1;i<n;i++)
		if(arr[curr]-arr[i]<2)
			return false;
	return true;
}
bool no_other_won(int *arr,int curr)
{
	for(int i=0;i<curr;i++)
		if(arr[i]!=0)return false;
	for(int i=curr+1;i<curr;i++)
		if(arr[i]!=0)return false;
	return true;
}
void getans()
{
	int len=strlen(str);
	char match;int curr;
	int set[11]={0},point[11]={0},game[11]={0};
	int count=0;
	bool game_win=false;
	while(count<len)
	{
		curr = str[count]-'A';
		if(point[curr]==3 && if_no_more_2(point,curr))
			game_win=true;
		else if(point[curr]==4)
			game_win=true;
		else if(!any_4(point))
			point[curr]++;
		
		if(game_win)
		{
			game_win=false;
			for(int i=0;i<n;i++)point[i]=0;
			game[curr]++;
			if(game[curr]>=6 && more_than_2(game,curr))
			{
				if(no_other_won(game,curr))set[curr]++;
				for(int i=0;i<n;i++)game[i]=0;
				set[curr]++;
				if(set[curr]>=3)
				{
					match='A'+curr;
					break;
				}
			}
		}
		count++;
	}
	cout<<count<< " "<< match<<endl;
}
int main()
{
	in_T
	{
		in_I(n);
		in_S(str);
		getans();
	}
}
