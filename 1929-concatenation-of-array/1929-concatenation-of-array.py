class Solution(object):
    def getConcatenation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        ans = [0] * (2*n)
        k = 0
        for i in nums:
            ans[k] = i
            k+=1
        
        
        j = n
        for i in nums:
            ans[j] = i
            j+=1
        
        
        return ans