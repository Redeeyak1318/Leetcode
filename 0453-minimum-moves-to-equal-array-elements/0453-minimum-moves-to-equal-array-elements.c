int minMoves(int* nums, int numsSize) {
    int mini = nums[0];
        int sum = 0;

        for(int i = 0; i < numsSize; i++) {
            mini = fmin(mini, nums[i]);
        }

        for(int i = 0; i < numsSize; i++) {
            sum += nums[i] - mini;
        }

        return sum;
}