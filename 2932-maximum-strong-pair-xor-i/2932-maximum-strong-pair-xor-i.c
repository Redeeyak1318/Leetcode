int maximumStrongPairXor(int* nums, int numsSize) {
    int ans = 0;

    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i; j < numsSize; j++)
        {
            if(abs(nums[i] - nums[j]) <= (nums[i] < nums[j] ? nums[i] : nums[j]))
            {
                if((nums[i] ^ nums[j]) > ans)
                    ans = nums[i] ^ nums[j];
            }
        }
    }

    return ans;
}