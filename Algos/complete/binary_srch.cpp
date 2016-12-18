//returns element >=n
int search_b(vector<int> &nums, int n)
{
    int start=0,end=nums.size()-1;
    int mid;
    while(start<end)
    {
        mid=(start+end)/2;
        if(nums[mid]<n)
        {
            start=mid+1;
            continue;
        }
        if(nums[mid]>=n)
        {
            end=mid;
            continue;
        }
    }
    return end;
}
