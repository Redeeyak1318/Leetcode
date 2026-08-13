class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        current_sum = 0
        min_len = 2147483647

        for right in range(0,len(nums)):
            current_sum += nums[right]

            while (current_sum >= target):
                current_len = right - left + 1
                if (current_len < min_len):
                    min_len = current_len
                
                current_sum -= nums[left]
                left+=1
            
        

        return 0 if min_len == 2147483647 else min_len