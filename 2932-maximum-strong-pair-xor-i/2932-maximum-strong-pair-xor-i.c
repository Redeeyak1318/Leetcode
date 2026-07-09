int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int maximumStrongPairXor(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int ans = 0;

    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i; j < numsSize && nums[j] <= 2 * nums[i]; j++)
        {
            int xr = nums[i] ^ nums[j];
            if(xr > ans)
                ans = xr;
        }
    }

    return ans;
}