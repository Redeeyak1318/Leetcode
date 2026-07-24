class Solution(object):
    def maximumCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(nums[0] > 0 or nums[len(nums) - 1] < 0):
            return len(nums)
        if(nums[0] == 0 and nums[len(nums) -1] == 0):
            return 0

        low = 0
        high = len(nums) - 1
        neg = 0
        pos = 0
        while(low <= high):
        
            mid = low + (high - low) // 2
            if(nums[mid] < 0):
                low = mid + 1
            else:
                high = mid - 1
        
        neg = low
        low = 0
        high = len(nums) - 1
        while(low < high):
        
            mid = low + (high - low) // 2
            if(nums[mid] > 0):
                high = mid
            else:
                low = mid + 1
        
        pos = len(nums) - low
        
        if(neg >= pos):
            return neg
        else:
            return pos