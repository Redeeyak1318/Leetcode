class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        newBest = 0
        n = len(nums)

        for i in range(0, n):
            if(nums[i] == 1):
                newBest+=1
                if(newBest > ans):
                    ans = newBest
            else:
                newBest = 0
        
        return ans