class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        currsum = 0
        maxsum = nums[0]
        for i in nums:
            currsum += i
            maxsum=max(maxsum,currsum)
            if(currsum < 0):
                currsum = 0
        
        return maxsum