class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = [0] * len(nums)
        k = 0
        for i in nums:
        
            val = i
            count = 0
            for j in nums:
            
                if(val>j):
                    count+=1
            
            ans[k] = count
            k+=1
        return ans