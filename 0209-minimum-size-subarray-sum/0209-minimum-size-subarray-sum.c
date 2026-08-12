int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int current_sum = 0;
    int min_len = INT_MAX;

    for (int right = 0; right < numsSize; right++) {
        current_sum += nums[right];

        while (current_sum >= target) {
            int current_len = right - left + 1;
            if (current_len < min_len) {
                min_len = current_len;
            }
            current_sum -= nums[left];
            left++;
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
}