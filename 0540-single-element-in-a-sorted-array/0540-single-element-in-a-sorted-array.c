int singleNonDuplicate(int* nums, int numsSize) {
    int low=0;
    int high=numsSize-1;
    while(low<high)
    {
        int mid=low + (high-low)/2;
        if(mid%2!=0)
        {
            if(nums[mid]==nums[mid-1])
            {
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        else{
            if(nums[mid]==nums[mid+1])
            {
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
    }
    return nums[low];
}