int maxSubArray(int* nums, int numsSize) {
    int currsum=0;
        int maxsum=nums[0];
        for(int i=0; i<numsSize; i++)
        {
            currsum+=nums[i];
            maxsum=fmax(maxsum,currsum);
            if(currsum<0)
            {
                currsum=0;
            }
        }
        return maxsum;
}