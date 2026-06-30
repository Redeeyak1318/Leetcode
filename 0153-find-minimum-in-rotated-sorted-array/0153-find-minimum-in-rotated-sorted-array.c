int findMin(int* nums, int numsSize) {
    int low=0;
    int high=numsSize-1;
    int min=INT_MAX;
    while(low<=high)
    {
        int mid=low + (high-low)/2;
        if(nums[mid]<min)
        {
            min=nums[mid];
        }
        else if(nums[high]<min)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return min;
}