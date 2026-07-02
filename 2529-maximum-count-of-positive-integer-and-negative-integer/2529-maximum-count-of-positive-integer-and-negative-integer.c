int maximumCount(int* nums, int numsSize) {
    if(nums[0] > 0 || nums[numsSize - 1] < 0)
        return numsSize;
    if(nums[0] == 0 && nums[numsSize -1] == 0)
        return 0;

    int low = 0;
    int high = numsSize - 1;
    int neg = 0;
    int pos = 0;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    neg = low;
    low = 0;
    high = numsSize - 1;
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] > 0)
            high = mid;
        else
            low = mid + 1;
    }
    pos = numsSize - low;
    
    if(neg >= pos)
        return neg;
    else
        return pos;
}