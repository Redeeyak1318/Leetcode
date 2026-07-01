int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize;
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] >= target)
        {
            high = mid;
        }
        else
            low = mid + 1;
    }
    return low;
}