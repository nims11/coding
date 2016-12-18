#include<iostream>
using namespace std;
struct attrib{
	int left,right,sum;
	attrib(int l,int r,int s)
	{
		left=l,right=r,sum=s;
	}
};
attrib find_max_mid_subarray(int *arr,int left,int mid,int right)
{
	int left_sum=arr[mid],sum=arr[mid],max_left=mid;
	for(int i=mid-1;i>=left;i--)
	{
		sum+=arr[i];
		if(sum>left_sum)
		{
			left_sum=sum;
			max_left=i;
		}
	}

	sum=arr[mid+1];
	int right_sum=arr[mid+1],max_right=mid+1;
	for(int i=mid+2;i<=right;i++)
	{
		sum+=arr[i];
		if(sum>right_sum)
		{
			right_sum=sum;
			max_right=i;
		}
	}

	return attrib(max_left,max_right,left_sum+right_sum);
}
attrib find_max_subarray(int *arr,int left,int right)
{
	int mid;
	if(left==right)
		return attrib(left,right,arr[left]);
	else mid=(left+right)/2;
	attrib left_max=find_max_subarray(arr,left,mid);
	attrib right_max=find_max_subarray(arr,mid+1,right);
	attrib mid_max=find_max_mid_subarray(arr,left,mid,right);
	
	if(left_max.sum>=right_max.sum && left_max.sum>=mid_max.sum)
		return left_max;
	else if(right_max.sum>=left_max.sum && right_max.sum>=mid_max.sum)
		return right_max;
	else
		return mid_max;
}
int main()
{
	int arr[100];
	int size;
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>arr[i];
	attrib X=find_max_subarray(arr,0,size-1);
	cout<<X.left<<" "<<X.right<<" "<<X.sum<<endl;	
	return 0;
}
