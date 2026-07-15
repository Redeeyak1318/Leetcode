int splitArray(int* nums, int numsSize, int k) {
    int low = nums[0];
    int high = nums[0];
    for(int i=1; i<numsSize; i++)
    {
        if(nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int minSum = 0;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int currsum = 0;
        int subArray = 1;
        for(int i=0; i<numsSize; i++)
        {
            if(currsum + nums[i] <= mid)
                currsum += nums[i];
            else
            {   
                subArray++;
                if(subArray > k)
                    break; 
                currsum = nums[i];
            }
        }
        if(subArray <= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}