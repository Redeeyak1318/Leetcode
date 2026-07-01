int smallestDivisor(int* nums, int numsSize, int threshold) {
    int low=1;
    int high=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]>high)
            high=nums[i];
    }
    while(low<high)
    {
        int mid=low + (high-low)/2;
        int thres=0;
        for(int i=0;i<numsSize;i++)
        {
            thres+=(nums[i]+mid-1)/mid;
        }
        if(thres<=threshold)
            high=mid;
        else
            low=mid+1;
    }
    return high;
}